# Use an official Ruby base image
FROM ruby:2.7

# Set environment variables for production use
ENV RAILS_ENV=production

# Install dependencies
RUN apt-get update -y &&     apt-get install -y build-essential libpq-dev nodejs

# Set working directory
WORKDIR /app

# Copy backend files
COPY ./backend /app

# Install Ruby Gems
RUN gem install bundler &&     bundle install

# Expose necessary ports
EXPOSE 80 443 8080
