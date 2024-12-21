import { GameState } from './types';
import { PADDLE_WIDTH, PADDLE_HEIGHT, BALL_SPEED } from './constants';

export function updateGameState(state: GameState, canvas: HTMLCanvasElement): GameState {
  let newState = { ...state };

  // Move ball
  newState.ballX += newState.ballSpeedX;
  newState.ballY += newState.ballSpeedY;

  // Ball collision with top and bottom
  if (newState.ballY <= 0 || newState.ballY >= canvas.height) {
    newState.ballSpeedY *= -1;
  }

  // Ball collision with paddles
  if (
    newState.ballX <= PADDLE_WIDTH &&
    newState.ballY >= newState.playerY &&
    newState.ballY <= newState.playerY + PADDLE_HEIGHT
  ) {
    newState.ballSpeedX *= -1;
  }

  if (
    newState.ballX >= canvas.width - PADDLE_WIDTH &&
    newState.ballY >= newState.aiY &&
    newState.ballY <= newState.aiY + PADDLE_HEIGHT
  ) {
    newState.ballSpeedX *= -1;
  }

  return newState;
}

export function updateAI(state: GameState): number {
  const aiCenter = state.aiY + PADDLE_HEIGHT / 2;
  if (aiCenter < state.ballY - 35) {
    return state.aiY + 4;
  } else if (aiCenter > state.ballY + 35) {
    return state.aiY - 4;
  }
  return state.aiY;
}

export function resetBall(canvas: HTMLCanvasElement): Pick<GameState, 'ballX' | 'ballY' | 'ballSpeedX' | 'ballSpeedY'> {
  return {
    ballX: canvas.width / 2,
    ballY: canvas.height / 2,
    ballSpeedX: BALL_SPEED * (Math.random() > 0.5 ? 1 : -1),
    ballSpeedY: BALL_SPEED * (Math.random() > 0.5 ? 1 : -1),
  };
}