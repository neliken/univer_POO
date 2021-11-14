#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stack>

class validate_expression {

public:

    bool check_pair (char open, char close) {

        if (open == '(' && close == ')')
            return 1;

        return 0; }

    bool is_parentheses_valid (std::string expression) {

        std::stack <char> opr;

        for (int i = 0; expression[i]; i++) {
            if (expression[i] == '(')
                opr.push (expression[i]);
            else if (expression[i] == ')') {
                if (opr.empty () || !check_pair (opr.top (), expression[i]) )
                    return false;
                else
                    opr.pop (); }
        }
        return opr.empty (); }

    bool is_char (std::string expression) {

        if (expression.size () > 1 )
            return false;

         switch (expression[0]) {
             case '+': return true;
             case '-': return true;
             case '*': return true;
             case '/': return true;
             case '(': return true;
             case ')': return true; }

        return false; }

    double solve (double a, double b, char ch) {
        switch (ch) {
            case '+': return (a + b);
            case '-': return (a - b);
            case '*': return (a * b);
            case '/': return (a / b); }

        return 0; }

    int precedence (char ch) {
        switch (ch) {
            case '+': return 1;
            case '-': return 1;
            case '*': return 2;
            case '/': return 2; }

        return 0; }

    double evaluate (std::string expression) {

        if (!is_parentheses_valid (expression) ) {
            std::cout << "Expression is not valid" << std::endl;
            exit (1); }

        std::stack <char> operators;
        std::stack <double> operands;

        std::string s;
        std::stringstream is (expression);

        while (is >> s) {
            if (is_char (s) ) {

                if (s[0] == '(')
                    operators.push (s[0]);

                else if (s[0] == ')') {
                    while (!operators.empty () && operators.top () != '(') {
                        char opr = operators.top (); operators.pop ();
                        double b = operands.top (); operands.pop ();
                        double a = operands.top (); operands.pop ();

                        operands.push (solve (a, b, opr) ); }
                    operators.pop(); }

                else {
                    while (!operators.empty () && precedence (operators.top () ) >= (precedence (s[0]) ) ) {
                        char opr = operators.top (); operators.pop ();
                        double b = operands.top (); operands.pop ();
                        double a = operands.top (); operands.pop ();

                        operands.push (solve (a, b, opr) ); }
                    operators.push (s[0]); }
            }

            else {
                double num = std::stod (s);
                operands.push (num); }
        }

        while (!operators.empty () ) {
            char opr = operators.top (); operators.pop ();
            double b = operands.top (); operands.pop ();
            double a = operands.top (); operands.pop ();

            operands.push (solve (a, b, opr) ); }

        return operands.top (); }
};

int main () {

    validate_expression validator;

   std::string read_exp;
  std::ifstream f ("three_expressions.txt");
      if (f.is_open () )
       while (getline (f, read_exp) ) {
           std::cout << read_exp << std::endl;

            validator.evaluate (read_exp) ? std::cout << "Correct" << std::endl : std::cout << "Incorrect" << std::endl;
       }
    f.close ();

    std::string s = "2 * 4 + ( 3 + 6 * 9 - 12 * ( 2 * 9 - 15 ) )  + 2 + ( -4 ) * ( ( 2 - 15 ) )";
    std::string one = "2x - 3y + 25 / ( 2 + 5 ) * 12 - ( ( 29 * 4 - 2 ) + 32 ) - 14";
    std::string two = "2x - 3y + 25 / ( - ( ( 29 * 4 - 2 ) + 32 ) - 14 - ( 2 + 5 ) * 12";
    std::string three = "( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( 2x - 4y * 98 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )";

    std::cout << "Result : " << validator.evaluate (two) << std::endl;

    return 0; }
