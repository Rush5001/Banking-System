
#include "../include/Notification.hpp"
#include <iostream>

Notification::Notification(const std::string& email, const std::string& subject, const std::string& message)
    : recipientEmail(email), subject(subject), messageBody(message) {}

void Notification::sendEmail() {
    // Placeholder logic to simulate sending an email
    std::cout << "Sending email to: " << recipientEmail << std::endl;
    std::cout << "Subject: " << subject << std::endl;
    std::cout << "Message: " << messageBody << std::endl;
}

void Notification::sendSMS(const std::string& phoneNumber) {
    // Placeholder logic to simulate sending an SMS
    std::cout << "Sending SMS to: " << phoneNumber << std::endl;
    std::cout << "Message: " << messageBody << std::endl;
}
