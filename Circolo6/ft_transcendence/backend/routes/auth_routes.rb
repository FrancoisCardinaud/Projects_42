# backend/routes/auth_routes.rb
require 'sinatra'
require 'bcrypt'
require_relative '../helpers/jwt_helper'
require 'sequel'

DB = Sequel.connect(ENV['DATABASE_URL'] || 'postgres://localhost/ft_transcendence')

# Create the users table if it doesn't exist
DB.create_table? :users do
  primary_key :id
  String :username, unique: true, null: false
  String :password_hash, null: false
  String :reset_token
end

# User Registration Endpoint
post '/register' do
  username = params[:username]
  password = params[:password]
  password_hash = BCrypt::Password.create(password)
  begin
    DB[:users].insert(username: username, password_hash: password_hash)
    "User #{username} registered successfully."
  rescue Sequel::UniqueConstraintViolation
    "Username already exists."
  end
end

# User Login Endpoint
post '/login' do
  username = params[:username]
  password = params[:password]
  user = DB[:users].where(username: username).first
  if user && BCrypt::Password.new(user[:password_hash]) == password
    token = generate_token({ user_id: user[:id], username: user[:username] })
    content_type :json
    { message: "Welcome, #{username}!", token: token }.to_json
  else
    status 401
    "Invalid credentials."
  end
end

# Password Reset Request Endpoint
post '/reset_password_request' do
  username = params[:username]
  user = DB[:users].where(username: username).first
  if user
    reset_token = SecureRandom.hex(10)
    DB[:users].where(id: user[:id]).update(reset_token: reset_token)
    "Password reset token generated for #{username}: #{reset_token}"
  else
    status 404
    "User not found."
  end
end

# Password Reset Endpoint
post '/reset_password' do
  username = params[:username]
  reset_token = params[:reset_token]
  new_password = params[:new_password]
  user = DB[:users].where(username: username, reset_token: reset_token).first
  if user
    new_password_hash = BCrypt::Password.create(new_password)
    DB[:users].where(id: user[:id]).update(password_hash: new_password_hash, reset_token: nil)
    "Password reset successful for #{username}."
  else
    status 400
    "Invalid reset token."
  end
end
