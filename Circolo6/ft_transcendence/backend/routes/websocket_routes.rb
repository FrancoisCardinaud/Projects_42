# backend/routes/websocket_routes.rb
require 'sinatra'
require 'faye/websocket'
require 'json'
require_relative '../models/game_room'

Faye::WebSocket.load_adapter('thin')

class TranscendenceApp < Sinatra::Base
  get '/websocket' do
    if Faye::WebSocket.websocket?(request.env)
      ws = Faye::WebSocket.new(request.env)

      ws.on :open do |event|
        ws.send({ message: 'WebSocket connection established' }.to_json)
      end

      ws.on :message do |event|
        data = JSON.parse(event.data)
        case data['action']
        when 'create_room'
          room_code = create_game_room(data['username'])
          ws.send({ message: 'Game room created', room_code: room_code }.to_json)
        when 'join_room'
          success = join_game_room(data['room_code'], data['username'])
          if success
            ws.send({ message: 'Joined game room successfully', room_code: data['room_code'] }.to_json)
          else
            ws.send({ error: 'Failed to join room' }.to_json)
          end
        when 'update_game_state'
          update_game_state(data['room_code'], data['game_state'])
          ws.send({ message: 'Game state updated', room_code: data['room_code'] }.to_json)
        when 'get_game_state'
          game_state = get_game_state(data['room_code'])
          ws.send({ message: 'Game state', game_state: game_state }.to_json)
        else
          ws.send({ error: 'Unknown action' }.to_json)
        end
      end

      ws.on :close do |event|
        ws = nil
      end

      ws.rack_response
    else
      status 426
      body 'WebSocket connection required'
    end
  end
end
