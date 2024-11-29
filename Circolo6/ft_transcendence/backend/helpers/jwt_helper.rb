# backend/helpers/jwt_helper.rb
require 'jwt'

SECRET_KEY = 'your_secret_key_here'

def generate_token(payload)
  JWT.encode(payload, SECRET_KEY, 'HS256')
end

def decode_token(token)
  JWT.decode(token, SECRET_KEY, true, { algorithm: 'HS256' })
end
