#ifndef MMA_FANDOM_H
#define MMA_FANDOM_H

#include <string>
#include <vector>
#include <ctime>
#include <memory>

// Forward declarations
class Fighter;
class FanClub;
class Event;
class Merchandise;
class FanInfluencer;
class TrainingCamp;
class Session;
class Trainer;
class Manager;
class Contract;

// Abstract class for Fan engagement strategies
class EngagementStrategy
{
public:
    virtual void engage() = 0;               // Pure virtual function for engagement
    virtual ~EngagementStrategy() = default; // Virtual destructor
};

// Derived classes for different engagement strategies
class Cheer : public EngagementStrategy
{
public:
    void engage() override; // Implementation of cheer engagement
};

class AttendMatch : public EngagementStrategy
{
public:
    void engage() override; // Implementation of attending match engagement
};

class FormFanClub : public EngagementStrategy
{
public:
    void engage() override; // Implementation of forming a fan club engagement
};

// Fan class definition
class Fan
{
private:
    std::string name;
    Fighter *favoriteFighter;
    FanClub *fanClub;
    std::unique_ptr<EngagementStrategy> engagementStrategy; // Engagement strategy

public:
    Fan(const std::string &name, Fighter *favoriteFighter);

    void setEngagementStrategy(std::unique_ptr<EngagementStrategy> strategy);
    void engage(); // Engage with the current strategy
};

// FighterStats class definition
class FighterStats
{
private:
    int wins;
    int losses;
    int draws;

public:
    void updateWins();
    void updateLosses();
    void updateDraws();
};

// Fighter class definition
class Fighter
{
private:
    std::string name;
    std::string rank;
    std::vector<std::unique_ptr<Match>> matches; // Use smart pointers for memory management
    FighterStats stats;

public:
    Fighter(const std::string &name, const std::string &rank);

    void perform();
    void train();
    void recover();
    FighterStats getStats();
};

// Match class definition
class Match
{
private:
    Fighter *fighterA;
    Fighter *fighterB;
    std::time_t date;
    std::string location;
    std::string result;

public:
    Match(Fighter *fighterA, Fighter *fighterB, const std::time_t &date, const std::string &location);

    void startMatch();
    void determineWinner();
};

// FanClub class definition
class FanClub
{
private:
    std::string name;
    std::vector<Fan *> members;
    Fighter *fighter;
    std::vector<std::unique_ptr<Event>> events; // Use smart pointers for memory management

public:
    FanClub(const std::string &name, Fighter *fighter);

    void addMember(Fan *fan);
    void removeMember(Fan *fan);
    void organizeEvent();
};

// Event class definition
class Event
{
private:
    std::string name;
    std::time_t date;
    std::string location;
    FanClub *fanClub;

public:
    Event(const std::string &name, const std::time_t &date, const std::string &location, FanClub *fanClub);

    void schedule();
    void cancel();
};

// Merchandise class definition
class Merchandise
{
private:
    std::string itemName;
    double price;
    Fighter *fighter;

public:
    Merchandise(const std::string &itemName, double price, Fighter *fighter);

    void display();
    void purchase();
};

// FanInfluencer class definition
class FanInfluencer
{
private:
    int followerCount;
    std::string platform;
    Fighter *promotedFighter;

public:
    FanInfluencer(int followerCount, const std::string &platform, Fighter *promotedFighter);

    void promoteFighter();
    void engageFollowers();
};

// TrainingCamp class definition
class TrainingCamp
{
private:
    std::string location;
    std::vector<Fighter *> scheduledFighters;
    std::vector<std::unique_ptr<Session>> trainingSessions; // Use smart pointers for memory management

public:
    TrainingCamp(const std::string &location);

    void observeTraining();
    void scheduleSession(std::unique_ptr<Session> session); // Use smart pointer
};

// Session class definition
class Session
{
private:
    std::time_t date;
    Fighter *fighter;
    int duration;

public:
    Session(const std::time_t &date, Fighter *fighter, int duration);

    void start();
    void end();
};

// Trainer class definition
class Trainer
{
private:
    std::string name;
    std::string expertise;
    std::vector<Fighter *> fighters;

public:
    Trainer(const std::string &name, const std::string &expertise);

    void trainFighter(Fighter *fighter);
    void provideFeedback(Fighter *fighter);
};

// Manager class definition
class Manager
{
private:
    std::string name;
    Fighter *fighter;
    std::vector<std::unique_ptr<Contract>> contracts; // Use smart pointers for memory management

public:
    Manager(const std::string &name, Fighter *fighter);

    void negotiateContract(std::unique_ptr<Contract> contract); // Use smart pointer
    void manageCareer(Fighter *fighter);
};

// Contract class definition
class Contract
{
private:
    std::string details;
    int duration;
    Fighter *fighter;

public:
    Contract(const std::string &details, int duration, Fighter *fighter);

    void signContract();
    void terminateContract();
};

#endif // MMA_FANDOM_H
