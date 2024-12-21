import React from 'react';
import { GameLogo } from './GameLogo';

interface LayoutProps {
  children: React.ReactNode;
}

export function Layout({ children }: LayoutProps) {
  return (
    <div className="min-h-screen bg-gray-900 text-white">
      <header className="border-b border-gray-800">
        <div className="container mx-auto px-4 py-4 flex items-center justify-between">
          <GameLogo />
          <nav className="space-x-6">
            <button className="hover:text-blue-400 transition-colors">Play</button>
            <button className="hover:text-blue-400 transition-colors">Leaderboard</button>
            <button className="hover:text-blue-400 transition-colors">Profile</button>
          </nav>
        </div>
      </header>
      <main className="container mx-auto px-4 py-8">
        {children}
      </main>
    </div>
  );
}