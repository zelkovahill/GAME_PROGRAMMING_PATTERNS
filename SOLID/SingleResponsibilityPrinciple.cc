#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 각각의 클래스가 단일 책을 가짐
class User
{
    public:
        string name;
        string email;
};

class UserRepository
{
    public:
        void save(const User& user)
        {
            // 데어터베이스에 사용자 저장
        }
};

class EmailService
{
    public:
        void sendEmail(const User& user)
        {
            // 이메일 전송
        }
};