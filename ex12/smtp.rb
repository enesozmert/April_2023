require 'net/smtp'
require 'mail'

# Set up the SMTP server configuration
smtp_config = {
  address: 'smtp.gmail.com',
  port: 587,
  domain: 'gmail.com',
  user_name: 'your_email@gmail.com',
  password: 'your_password',
  authentication: 'plain',
  enable_starttls_auto: true
}

# Set up the email message
message = Mail.new do
  from    'your_email@gmail.com'
  to      'recipient_email@example.com'
  subject 'Test email with attachment'
  body    'Hello, this is a test email with an attachment.'
end

# Send the email using SMTP
Net::SMTP.start(smtp_config[:address], smtp_config[:port], smtp_config[:domain],
                smtp_config[:user_name], smtp_config[:password], smtp_config[:authentication]) do |smtp|
  smtp.send_message message.to_s, message.from.first, message.to.first
end

puts "Email sent successfully."