import React from 'react';
import { GameBoard } from './components/GameBoard';
import { Layout } from './components/Layout';
import { AuthPages } from './components/auth/AuthPages';
import { AuthProvider, useAuth } from './context/AuthContext';

function AppContent() {
  const { user, isLoading } = useAuth();

  if (isLoading) {
    return <div>Loading...</div>;
  }

  return (
    <Layout>
      {user ? <GameBoard /> : <AuthPages />}
    </Layout>
  );
}

function App() {
  return (
    <AuthProvider>
      <AppContent />
    </AuthProvider>
  );
}

export default App;