import React, { useEffect, useRef } from 'react';
import { useGame } from '../hooks/useGame';

export function GameBoard() {
  const canvasRef = useRef<HTMLCanvasElement>(null);
  const { startGame, gameState } = useGame(canvasRef);

  useEffect(() => {
    const cleanup = startGame();
    return () => {
      if (cleanup) cleanup();
    };
  }, [startGame]);

  return (
    <div className="flex flex-col items-center space-y-6">
      <div className="flex justify-between w-full max-w-2xl px-8">
        <div className="text-2xl font-bold">Player: {gameState.playerScore}</div>
        <div className="text-2xl font-bold">AI: {gameState.aiScore}</div>
      </div>
      <canvas
        ref={canvasRef}
        width={800}
        height={400}
        className="bg-black rounded-lg border-4 border-blue-500"
      />
      <div className="space-x-4">
        <button 
          className="px-6 py-2 bg-blue-500 rounded-lg hover:bg-blue-600 transition-colors"
          onClick={() => startGame()}
        >
          New Game
        </button>
      </div>
    </div>
  );
}