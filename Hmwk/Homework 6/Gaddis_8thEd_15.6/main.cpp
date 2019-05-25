#include <iostream>

using namespace std;

class GradedActivity {
protected:
    double score;
public:

    GradedActivity() {
        score = 0.0;
    }

    GradedActivity(double s) {
        score = s;
    }

    void setScore(double s) {
        score = s;
    }

    double getScore() const {
        return score;
    }

    char getLetterGrade() const {
        char letterGrade;

        if (score > 89)
            letterGrade = 'A';
        else if (score > 79)
            letterGrade = 'B';
        else if (score > 69)
            letterGrade = 'C';
        else if (score > 59)
            letterGrade = 'D';
        else
            letterGrade = 'F';

        return letterGrade;
    }
};

class Essay : public GradedActivity {
private:
    double _grammar, _spelling, _length, _content;
public:
    Essay() {
        score = 0.0;
    };

    Essay(double grammar, double spelling, double length, double content) {
        if (grammar <= 30 && spelling <= 20 && length <= 20 && content <= 30) {
            score = grammar + spelling + length + content;
            _grammar = grammar;
            _spelling = spelling;
            _length = length;
            _content = content;
        } else {
            cout << "Invalid score entry" << endl;
        }
    }
};

int main() {
    Essay essay(30, 20, 20, 30);
    
    cout << "Students Grade: " << essay.getLetterGrade();
}