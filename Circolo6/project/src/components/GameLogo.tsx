import React from 'react';
import { Table } from 'lucide-react';

export function GameLogo() {
  return (
    <div className="flex items-center space-x-2">
      <Table className="w-8 h-8 text-blue-400" />
      <span className="text-xl font-bold">Transcendence</span>
    </div>
  );
}