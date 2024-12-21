import { useCallback, useRef, useState } from 'react';
import { GameState } from '../game/types';
import { INITIAL_STATE, PADDLE_HEIGHT } from '../game/constants';
import { updateGameState, updateAI, resetBall } from '../game/physics';
import { renderGame } from '../game/renderer';

export function useGame(canvasRef: React.RefObject<HTMLCanvasElement>) {
  const [gameState, setGameState] = useState<GameState>(INITIAL_STATE);
  const gameStateRef = useRef<GameState>(INITIAL_STATE);
  const animationFrameId = useRef<number>();
  const mouseMoveHandler = useRef<(e: MouseEvent) => void>();

  const updateGame = useCallback(() => {
    const canvas = canvasRef.current;
    if (!canvas) return;

    // Use ref for state updates to avoid render loop
    const currentState = gameStateRef.current;
    let newState = updateGameState(currentState, canvas);

    // Update AI position
    newState.aiY = updateAI(newState);

    // Check for scoring
    if (newState.ballX <= 0) {
      newState = {
        ...newState,
        aiScore: currentState.aiScore + 1,
        ...resetBall(canvas),
      };
    } else if (newState.ballX >= canvas.width) {
      newState = {
        ...newState,
        playerScore: currentState.playerScore + 1,
        ...resetBall(canvas),
      };
    }

    // Update both ref and state
    gameStateRef.current = newState;
    setGameState(newState);

    // Render game
    const ctx = canvas.getContext('2d');
    if (ctx) {
      renderGame(ctx, canvas, newState);
    }

    animationFrameId.current = requestAnimationFrame(updateGame);
  }, [canvasRef]); // Remove gameState from dependencies

  const startGame = useCallback(() => {
    if (animationFrameId.current) {
      cancelAnimationFrame(animationFrameId.current);
    }

    // Remove existing mouse move handler
    if (mouseMoveHandler.current && canvasRef.current) {
      canvasRef.current.removeEventListener('mousemove', mouseMoveHandler.current);
    }
    
    const initialState = { ...INITIAL_STATE };
    setGameState(initialState);
    gameStateRef.current = initialState;

    const canvas = canvasRef.current;
    if (!canvas) return;

    // Create and store new mouse move handler
    mouseMoveHandler.current = (e: MouseEvent) => {
      const rect = canvas.getBoundingClientRect();
      const mouseY = e.clientY - rect.top;
      const newY = Math.min(
        Math.max(mouseY - PADDLE_HEIGHT / 2, 0),
        canvas.height - PADDLE_HEIGHT
      );
      
      // Update both ref and state
      gameStateRef.current = { ...gameStateRef.current, playerY: newY };
      setGameState(prev => ({ ...prev, playerY: newY }));
    };

    canvas.addEventListener('mousemove', mouseMoveHandler.current);
    animationFrameId.current = requestAnimationFrame(updateGame);

    // Cleanup function
    return () => {
      if (animationFrameId.current) {
        cancelAnimationFrame(animationFrameId.current);
      }
      if (mouseMoveHandler.current && canvas) {
        canvas.removeEventListener('mousemove', mouseMoveHandler.current);
      }
    };
  }, [canvasRef, updateGame]);

  return { startGame, gameState };
}