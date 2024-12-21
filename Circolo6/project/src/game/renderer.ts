import { GameState } from './types';
import { PADDLE_WIDTH, PADDLE_HEIGHT, BALL_SIZE } from './constants';

export function renderGame(ctx: CanvasRenderingContext2D, canvas: HTMLCanvasElement, state: GameState) {
  // Clear canvas
  ctx.fillStyle = '#000';
  ctx.fillRect(0, 0, canvas.width, canvas.height);

  ctx.fillStyle = '#fff';
  
  // Draw paddles
  ctx.fillRect(0, state.playerY, PADDLE_WIDTH, PADDLE_HEIGHT);
  ctx.fillRect(
    canvas.width - PADDLE_WIDTH,
    state.aiY,
    PADDLE_WIDTH,
    PADDLE_HEIGHT
  );

  // Draw ball
  ctx.fillRect(
    state.ballX - BALL_SIZE / 2,
    state.ballY - BALL_SIZE / 2,
    BALL_SIZE,
    BALL_SIZE
  );

  // Draw center line
  ctx.setLineDash([5, 15]);
  ctx.beginPath();
  ctx.moveTo(canvas.width / 2, 0);
  ctx.lineTo(canvas.width / 2, canvas.height);
  ctx.strokeStyle = '#fff';
  ctx.stroke();
}