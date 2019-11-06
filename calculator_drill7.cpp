#include "std_lib_facilities_modded.h"


struct Token {
    // All Tokens have a 'kind', value and NAME are optional
	char kind;
	double value;
	string NAME;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
    Token(char ch, string s) :kind(ch), NAME(s) { }
};

const char LET = '#';
const char QUIT = 'Q';
const char PRINT = ';';
const char NUMBER = '8';
const char NAME = 'a';
const char SQRT = '?';
const char EXPONENT = '^';

class Token_stream {
	bool full;
	Token buffer;
public:
    // Constructor
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer=t; full=true; }

	void ignore(char);
};

Token Token_stream::get()
{
	if (full) { full=false; return buffer; }

	char ch;
	cin >> ch;
	switch (ch) {
    case QUIT:
    case SQRT:
    case EXPONENT:
    case LET:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
        cin.putback(ch);
		double val;
		cin >> val;
		return Token(NUMBER,val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;

			while(cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                s += ch;

			cin.putback(ch);
			//if (s == "LET") return Token(LET);
			if (s == "exit") return Token(QUIT);

			if (s == "sqrt") return Token(SQRT);

            if (s == "pow") return Token(EXPONENT);

			return Token(NAME,s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

struct Variable {
	string NAME;
	double value;
	Variable(string n, double v) :NAME(n), value(v) { }
};

vector<Variable> var_names;

double get_value(string s)
{
	for (int i = 0; i<var_names.size(); ++i)
		if (var_names[i].NAME == s) return var_names[i].value;
	error("get: undefined NAME ",s);
}

void set_value(string s, double d)
{
	for (int i = 0; i<var_names.size(); ++i)
		if (var_names[i].NAME == s) {
			var_names[i].value = d;
			return;
		}
	error("set: undefined NAME ",s);
}

bool is_declared(string s)
    // checks to see if a given variable NAME has already been declared
{
	for (int i = 0; i<var_names.size(); ++i)
		if (var_names[i].NAME == s) return true;
	return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
        return d;
	}
	case '-':
		return - primary();
	case NUMBER:
		return t.value;
	case NAME:
		return get_value(t.NAME);
    case SQRT:
        {
            double d = primary();
            if (d < 0) error("Can't sqrt() Imaginary #");
            return sqrt(d);
        }
	default:
		error("primary expected");
	}
}

double pow(double base, double exp)
{
    int x = narrow_cast<int>(exp);

    double n = 1;
    double b;

    if (exp < 0) {
        b = 1 / base;
        x *= -1;
    } else
        b = base;

    for (int i = 0; i < x; ++i)
        n *= b;

    return n;
}

double secondary()
{
    double left = primary();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
            case '^':
                return pow(left, primary());
            default:
                ts.unget(t);
                return left;
        }
    }
}

double term()
{
	double left = secondary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= secondary();
			break;
		case '/':
		{
            double d = secondary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != NAME) error ("Name expected in declaration");
	string NAME = t.NAME;

	if (is_declared(NAME)) error(NAME, " declared twice");

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,NAME);

	double d = expression();
	var_names.push_back(Variable(NAME,d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case LET:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(PRINT);
}

const string prompt = "> ";
const string result = "= ";
const string welcome = "WELCOME ";

void calculate()
{
    //Predefined values
    var_names.push_back(Variable("pi", 3.14159));
    var_names.push_back(Variable("e", 2.718281828));
    var_names.push_back(Variable("k", 1000));

	while(true) try {

		cout << prompt;
		Token t = ts.get();
		while (t.kind == PRINT) t=ts.get();
		if (t.kind == QUIT) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main(){
    cout << "Welcome to the simple calculator \n";
    cout <<"Currently available operators are: '(', ')', '*', '/', '+', '-', '^' and '?'-> to square root. \n";
    cout <<"There are some predefined values: pi, e, k . \n";
    cout << "You can define your values like: '# x=15;'. \n";
    cout <<"Use ';' to to get result or 'Q;' to quit the program.\n";
	try {

		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
}
