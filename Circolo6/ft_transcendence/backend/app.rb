# backend/app.rb
require 'sinatra'
require 'sequel'
require_relative './routes/auth_routes'
require_relative './routes/websocket_routes'

DB = Sequel.connect(ENV['DATABASE_URL'] || 'postgres://localhost/ft_transcendence')

# Start the Sinatra server
class TranscendenceApp < Sinatra::Base
  get '/' do
    "Welcome to ft_transcendence Backend!"
  end

  # Add additional configurations if needed
end
