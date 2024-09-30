
#ifndef NOTIFICATION_HPP
#define NOTIFICATION_HPP

#include <string>

class Notification {
private:
    std::string recipientEmail;
    std::string subject;
    std::string messageBody;

public:
    Notification(const std::string& email, const std::string& subject, const std::string& message);

    void sendEmail();
    void sendSMS(const std::string& phoneNumber);
};

#endif
