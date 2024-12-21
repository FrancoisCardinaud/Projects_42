module Api
  class AuthController < ApplicationController
    skip_before_action :authenticate_request, only: [:login, :register]

    def login
      user = User.find_by(username: params[:username])
      if user&.authenticate(params[:password])
        token = jwt_encode(user_id: user.id)
        render json: { 
          token: token,
          user: {
            id: user.id,
            username: user.username,
            email: user.email
          }
        }
      else
        render json: { error: 'Invalid username or password' }, status: :unauthorized
      end
    end

    def register
      user = User.new(user_params)
      if user.save
        token = jwt_encode(user_id: user.id)
        render json: {
          token: token,
          user: {
            id: user.id,
            username: user.username,
            email: user.email
          }
        }, status: :created
      else
        render json: { errors: user.errors.full_messages }, status: :unprocessable_entity
      end
    end

    private

    def user_params
      params.permit(:username, :email, :password, :password_confirmation)
    end
  end
end
