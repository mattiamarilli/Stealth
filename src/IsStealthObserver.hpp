//
// Created by mattia on 21/08/20.
//

#ifndef STEALTH_ISSTEALTHOBSERVER_HPP
#define STEALTH_ISSTEALTHOBSERVER_HPP


class IsStealthObserver {
public:
    virtual ~IsStealthObserver() {
        std::cout << "Goodbye, I was the IsStealthObserver"<<std::endl;
    }
    virtual void changeStealthStatus() = 0;
};


#endif //STEALTH_ISSTEALTHOBSERVER_HPP
