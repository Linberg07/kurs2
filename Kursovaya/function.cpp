#include<iostream>
#include<sstream>
#include "function.h"

using namespace std;


string convertInt(double number)
{
	stringstream ss;
	ss << number;
	return ss.str();
}
string string_exp(string infix) {
	for (int i = 0; i < infix.length(); i++) {

		if (infix[i] == 'e') {
			string res = Expon;
			int in_bef;
			
			in_bef = i ;
			int in_aft;
			 in_aft = i;
			int swap = (in_aft - in_bef + 1) - res.length();
			if (swap >= 0) {
				for (int z = 0; z < res.length(); z++) {
					infix[in_bef] = res[z];
					in_bef++;
				}
				if (swap != 0) {
					for (int g = 0; g < swap; g++) {
						for (int z = in_aft - swap + 1; z < infix.length(); z++) {
							infix[z] = infix[z + 1];
						}
					}
					string temp = "";
					for (int z = 0; z < infix.length() - swap; z++) {
						temp = temp + infix[z];
					}
					infix = temp;
				}
			}
			if (swap < 0) {
				string temp = infix;
				for (int z = 0; z < (swap * (-1)); z++) {
					temp = temp + " ";
				}
				for (int z = infix.length(); z > in_aft; z--) {
					temp[z + (swap * (-1))] = temp[z];
				}
				for (int z = 0; z < res.length(); z++) {
					temp[in_bef] = res[z];
					in_bef++;
				}
				infix = temp;
			}
			i = i - swap;
		}
	}
	return infix;
}
int check_string(string infix) {
	char symbol[19] = { '0','1','2','3','4','5','6','7','8','9','+','-','*','/','^','(',')','.','e'};
	char replay_symbol[6] = { '+','-','*','/','^','.' };
	int brackets_open = 0;
	int brackets_close = 0;
	for (int i = 0; i < infix.length(); i++) {
		int k = 0;

		if ((infix[i] == 'c') && (infix[i + 1] == 'o') && (infix[i + 2] == 's')) k = k - 3;
		if (i > 0) {
			if ((infix[i] == 'o') && (infix[i - 1] == 'c') && (infix[i + 1] == 's')) k = k - 3;
			if (i > 1) {
				if ((infix[i] == 's') && (infix[i - 1] == 'o') && (infix[i - 2] == 'c')) k = k - 3;
			}
		}

		if ((infix[i] == 's') && (infix[i + 1] == 'i') && (infix[i + 2] == 'n')) k = k - 3;
		if ((infix[i] == 'i') && (infix[i - 1] == 's') && (infix[i + 1] == 'n')) k = k - 3;
		if ((infix[i] == 'n') && (infix[i - 1] == 'i') && (infix[i - 2] == 's')) k = k - 3;

		if ((infix[i] == 'c') && (infix[i + 1] == 't') && (infix[i + 2] == 'g')) k = k - 3;
		if ((infix[i] == 't') && (infix[i - 1] == 'c') && (infix[i + 1] == 'g')) k = k - 3;
		if ((infix[i] == 'g') && (infix[i - 1] == 't') && (infix[i - 2] == 'c')) k = k - 3;

		if ((infix[i] == 'l') && (infix[i + 1] == 'o') && (infix[i + 2] == 'g')) k = k - 3;
		if ((infix[i] == 'o') && (infix[i - 1] == 'l') && (infix[i + 1] == 'g')) k = k - 3;
		if ((infix[i] == 'g') && (infix[i - 1] == 'o') && (infix[i - 2] == 'l')) k = k - 3;


		if ((infix[i] == 't') && (infix[i + 1] == 'g')) k = k - 2;
		if ((infix[i] == 'g') && (infix[i - 1] == 't')) k = k - 2;

		if ((infix[i] == 'p') && (infix[i + 1] == 'i')) k = k - 2;
		if ((infix[i] == 'i') && (infix[i - 1] == 'p')) k = k - 2;

		if ((infix[i] == 'l') && (infix[i + 1] == 'n')) k = k - 2;
		if ((infix[i] == 'n') && (infix[i - 1] == 'l')) k = k - 2;

		bool replay = false;
		for (int j = 0; j < 19; j++) {
			if (infix[i] != symbol[j]) k++;
		}
		for (int j = 0; j < 6; j++) {
			if ((infix[i] == replay_symbol[j]) && (infix[i + 1] == replay_symbol[j])) replay = true;
		}

		if (infix[i] == '(') brackets_open++;
		if (infix[i] == ')') brackets_close++;

		if ((k == 19)) {
			cout << "Error in symbol " << i << " pos"; return 0; throw "Error in symbol";
		}
		if (replay) {
			cout << "Replay symbol in " << i << " pos"; return 0;throw "Replay symbol";
		}
	}
	if (brackets_close != brackets_open) {
		cout << "Invalid parentheses"; return 0; throw "Invalid parentheses";
	}
}
void string_to_double(double& a, double& b, string after, string before) {
	bool fractional_a = false;
	int after_point_a = 0;
	for (int j = 0; j < before.length(); j++) {
		if (before[j] == '.') fractional_a = true;
		if (fractional_a) after_point_a++;
	}
	after_point_a--;


	double mult;
	if (fractional_a)  mult = 1 / (pow(10, after_point_a));
	else mult = 1;
	int after_point_b = 0;
	bool fractional_b = false;
	for (int j = 0; j < after.length(); j++) {
		if (after[j] == '.') fractional_b = true;
		if (fractional_b) after_point_b++;
	}
	after_point_b--;
	for (int j = before.length() - 1; j >= 0; j--) {
		if (before[j] == '.') {
			fractional_a = false; mult = 1; continue;
		}

		if (fractional_a) {
			a = a + double(before[j] - 48) * mult;
			mult *= 10;
		}
		else {
			a = a + double(before[j] - 48) * mult;
			mult *= 10;
		}
	}
	if (fractional_b)  mult = 1 / (pow(10, after_point_b));
	else mult = 1;
	for (int j = after.length() - 1; j >= 0; j--) {
		if (after[j] == '.') {
			fractional_b = false; mult = 1; continue;
		}

		if (fractional_b) {
			b = b + int(after[j] - 48) * mult;
			mult *= 10;
		}
		else {
			b = b + int(after[j] - 48) * mult;
			mult *= 10;
		}
	}
}
void one_string_to_double(double& b, string after) {

	double mult;

	int after_point_b = 0;
	bool fractional_b = false;
	for (int j = 0; j < after.length(); j++) {
		if (after[j] == '.') fractional_b = true;
		if (fractional_b) after_point_b++;
	}
	after_point_b--;

	if (fractional_b)  mult = 1 / (pow(10, after_point_b));
	else mult = 1;
	for (int j = after.length() - 1; j >= 0; j--) {
		if (after[j] == '.') {
			fractional_b = false; mult = 1; continue;
		}

		if (fractional_b) {
			b = b + int(after[j] - 48) * mult;
			mult *= 10;
		}
		else {
			b = b + int(after[j] - 48) * mult;
			mult *= 10;
		}
	}
}
string string_power(string infix) {
	for (int i = 0; i < infix.length(); i++) {

		if (infix[i] == '^') {
			string after;
			string before;
			int j = i - 1;
			while ((j >= 0) && (infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/')) {
				before = before + infix[j];
				j--;
			}
			j = i + 1;
			while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j < infix.length())) {
				after = after + infix[j];
				j++;
			}
			for (j = 0; j < before.length() / 2; j++) {
				char swap = before[j];
				before[j] = before[before.length() - j - 1];
				before[before.length() - j - 1] = swap;

			}
			int a = 0;
			int mult = 1;
			int b = 0;;
			for (int j = before.length() - 1; j >= 0; j--) {
				a = a + int(before[j] - 48) * mult;
				mult *= 10;
			}
			mult = 1;
			for (int j = after.length() - 1; j >= 0; j--) {
				b = b + int(after[j] - 48) * mult;
				mult *= 10;
			}

			int result = pow(a, b);
			string res = convertInt(result);
			int in_bef = i - before.length();
			int in_aft = i + after.length();
			int swap = (in_aft - in_bef + 1) - res.length();
			if (swap >= 0) {
				for (int z = 0; z < res.length(); z++) {
					infix[in_bef] = res[z];
					in_bef++;
				}
				if (swap != 0) {
					for (int g = 0; g < swap; g++) {
						for (int z = in_aft - swap + 1; z < infix.length(); z++) {
							infix[z] = infix[z + 1];
						}
					}
					string temp = "";
					for (int z = 0; z < infix.length() - swap; z++) {
						temp = temp + infix[z];
					}
					infix = temp;
				}
			}
			if (swap < 0) {
				string temp = infix;
				for (int z = 0; z < (swap * (-1)); z++) {
					temp = temp + " ";
				}
				for (int z = infix.length(); z > in_aft; z--) {
					temp[z + (swap * (-1))] = temp[z];
				}
				for (int z = 0; z < res.length(); z++) {
					temp[in_bef] = res[z];
					in_bef++;
				}
				infix = temp;
			}
			i = i - swap;
		}
	}
	return infix;
}
string string_multiplication(string infix) {
	for (int i = 0; i < infix.length(); i++) {

		if (infix[i] == '*') {
			string after;
			string before;
			int j = i - 1;
			bool minus_b = false;
			while ((j >= 0) && (infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/')) {
				before = before + infix[j];
				j--;
			}
			if (j >= 0) {
				if (infix[j] == '-') minus_b = true;
			}
			j = i + 1;
			bool minus = false;
			while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j < infix.length())) {
				after = after + infix[j];
				j++;
			}
			if (infix[j] == '-') minus = true;
			if (minus) {
				j++;
				while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j < infix.length())) {
					after = after + infix[j];
					j++;
				}
			}

			for (j = 0; j < before.length() / 2; j++) {
				char swap = before[j];
				before[j] = before[before.length() - j - 1];
				before[before.length() - j - 1] = swap;

			}
			double a = 0;
			double b = 0;;

			string_to_double(a, b, after, before);
			double result;
			if (minus == true) b = b * (-1);

			if (minus_b) a = a * (-1);
			result = a * b;

			string res = convertInt(result);
			int in_bef;
			if (minus_b) in_bef = i - before.length() - 1;
			else in_bef = i - before.length();
			int in_aft;
			if (minus) in_aft = i + after.length() + 1;
			else  in_aft = i + after.length();
			int swap = (in_aft - in_bef + 1) - res.length();
			if (swap >= 0) {
				for (int z = 0; z < res.length(); z++) {
					infix[in_bef] = res[z];
					in_bef++;
				}
				if (swap != 0) {
					for (int g = 0; g < swap; g++) {
						for (int z = in_aft - swap + 1; z < infix.length(); z++) {
							infix[z] = infix[z + 1];
						}
					}
					string temp = "";
					for (int z = 0; z < infix.length() - swap; z++) {
						temp = temp + infix[z];
					}
					infix = temp;
				}
			}
			if (swap < 0) {
				string temp = infix;
				for (int z = 0; z < (swap * (-1)); z++) {
					temp = temp + " ";
				}
				for (int z = infix.length(); z > in_aft; z--) {
					temp[z + (swap * (-1))] = temp[z];
				}
				for (int z = 0; z < res.length(); z++) {
					temp[in_bef] = res[z];
					in_bef++;
				}
				infix = temp;
			}
			i = i - swap;
		}
	}
	return infix;
}
string string_division(string infix) {
	for (int i = 0; i < infix.length(); i++) {

		if (infix[i] == '/') {
			string after;
			string before;
			int j = i - 1;
			bool minus_b = false;
			while ((j >= 0) && (infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/')) {
				before = before + infix[j];
				j--;
			}
			if (j >= 0) {
				if (infix[j] == '-') minus_b = true;
			}
			j = i + 1;
			bool minus = false;
			while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j < infix.length())) {
				after = after + infix[j];
				j++;
			}
			if (infix[j] == '-') minus = true;
			if (minus) {
				j++;
				while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j < infix.length())) {
					after = after + infix[j];
					j++;
				}
			}

			for (j = 0; j < before.length() / 2; j++) {
				char swap = before[j];
				before[j] = before[before.length() - j - 1];
				before[before.length() - j - 1] = swap;

			}
			double a = 0;
			double b = 0;;

			string_to_double(a, b, after, before);
			double result;
			if (minus == true) b = b * (-1);

			if (minus_b) a = a * (-1);
			result = a / b;

			string res = convertInt(result);
			int in_bef;
			if (minus_b) in_bef = i - before.length() - 1;
			else in_bef = i - before.length();
			int in_aft;
			if (minus) in_aft = i + after.length() + 1;
			else  in_aft = i + after.length();
			int swap = (in_aft - in_bef + 1) - res.length();
			if (swap >= 0) {
				for (int z = 0; z < res.length(); z++) {
					infix[in_bef] = res[z];
					in_bef++;
				}
				if (swap != 0) {
					for (int g = 0; g < swap; g++) {
						for (int z = in_aft - swap + 1; z < infix.length(); z++) {
							infix[z] = infix[z + 1];
						}
					}
					string temp = "";
					for (int z = 0; z < infix.length() - swap; z++) {
						temp = temp + infix[z];
					}
					infix = temp;
				}
			}
			if (swap < 0) {
				string temp = infix;
				for (int z = 0; z < (swap * (-1)); z++) {
					temp = temp + " ";
				}
				for (int z = infix.length(); z > in_aft; z--) {
					temp[z + (swap * (-1))] = temp[z];
				}
				for (int z = 0; z < res.length(); z++) {
					temp[in_bef] = res[z];
					in_bef++;
				}
				infix = temp;
			}
			i = i - swap;
		}
	}
	return infix;
}
string string_addition(string infix) {
	for (int i = 0; i < infix.length(); i++) {

		if (infix[i] == '+') {
			string after;
			string before;
			int j = i - 1;
			while ((j >= 0) && (infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/')) {
				before = before + infix[j];
				j--;
			}
			bool minus = false;
			if (j >= 0) {
				if (infix[j] == '-') minus = true;
			}
			j = i + 1;
			while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j < infix.length())) {
				after = after + infix[j];
				j++;
			}
			int before_num = before.length();
			before = "";
			for (int j = i - before_num; j < i; j++) {
				before = before + infix[j];
			}

			double a = 0;
			double b = 0;

			string_to_double(a, b, after, before);
			if (minus) a = a * (-1);


			double result = a + b;
			string res = convertInt(result);
			int in_bef;

			if (minus) in_bef = i - before.length() - 1;
			else in_bef = i - before.length();

			int in_aft = i + after.length();
			int swap = (in_aft - in_bef + 1) - res.length();
			if (swap >= 0) {
				for (int z = 0; z < res.length(); z++) {
					infix[in_bef] = res[z];
					in_bef++;
				}
				if (swap != 0) {
					for (int g = 0; g < swap; g++) {
						for (int z = in_aft - swap + 1; z < infix.length(); z++) {
							infix[z] = infix[z + 1];
						}
					}
					string temp = "";
					for (int z = 0; z < infix.length() - swap; z++) {
						temp = temp + infix[z];
					}
					infix = temp;
				}
			}
			if (swap < 0) {
				string temp = infix;
				for (int z = 0; z < (swap * (-1)); z++) {
					temp = temp + " ";
				}
				for (int z = infix.length(); z > in_aft; z--) {
					temp[z + (swap * (-1))] = temp[z];
				}
				for (int z = 0; z < res.length(); z++) {
					temp[in_bef] = res[z];
					in_bef++;
				}
				infix = temp;
			}
			i = i - swap;
		}
	}
	return infix;
}
string string_computation(string infix) {
	for (int i = 0; i < infix.length(); i++) {

		if (infix[i] == '-') {
			string after;
			string before;
			int j = i - 1;
			while ((j >= 0) && (infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/')) {
				before = before + infix[j];
				j--;
			}
			bool minus_before = false;
			if (j >= 0) {
				if (infix[j] == '-') minus_before = true;
			}
			j = i + 1;
			while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j < infix.length())) {
				after = after + infix[j];
				j++;
			}
			for (j = 0; j < before.length() / 2; j++) {
				char swap = before[j];
				before[j] = before[before.length() - j - 1];
				before[before.length() - j - 1] = swap;

			}
			double a = 0;
			double b = 0;;

			string_to_double(a, b, after, before);

			double result;
			if (minus_before) {
				result = (a + b) * (-1);
			}
			else {
				result = a - b;
			}
			string res = convertInt(result);
			int in_bef;
			if (minus_before) {
				in_bef = i - before.length() - 1;
			}
			else {
				in_bef = i - before.length();
			}
			int in_aft = i + after.length();
			int swap = (in_aft - in_bef + 1) - res.length();
			if (swap >= 0) {
				for (int z = 0; z < res.length(); z++) {
					infix[in_bef] = res[z];
					in_bef++;
				}
				if (swap != 0) {
					for (int g = 0; g < swap; g++) {
						for (int z = in_aft - swap + 1; z < infix.length(); z++) {
							infix[z] = infix[z + 1];
						}
					}
					string temp = "";
					for (int z = 0; z < infix.length() - swap; z++) {
						temp = temp + infix[z];
					}
					infix = temp;
				}
			}
			if (swap < 0) {
				string temp = infix;
				for (int z = 0; z < (swap * (-1)); z++) {
					temp = temp + " ";
				}
				for (int z = infix.length(); z > in_aft; z--) {
					temp[z + (swap * (-1))] = temp[z];
				}
				for (int z = 0; z < res.length(); z++) {
					temp[in_bef] = res[z];
					in_bef++;
				}
				infix = temp;
			}
			i = i - swap;
		}
	}
	return infix;
}
string string_pi(string infix) {
	for (int i = 0; i < infix.length(); i++) {

		if ((infix[i] == 'p') && (infix[i + 1] == 'i')) {
			string res = pi;
			int in_bef = i;
			int in_aft = i+1 ;
			int swap = (in_aft - in_bef + 1) - res.length();
			if (swap >= 0) {
				for (int z = 0; z < res.length(); z++) {
					infix[in_bef] = res[z];
					in_bef++;
				}
				if (swap != 0) {
					for (int g = 0; g < swap; g++) {
						for (int z = in_aft - swap + 1; z < infix.length(); z++) {
							infix[z] = infix[z + 1];
						}
					}
					string temp = "";
					for (int z = 0; z < infix.length() - swap; z++) {
						temp = temp + infix[z];
					}
					infix = temp;
				}
			}
			if (swap < 0) {
				string temp = infix;
				for (int z = 0; z < (swap * (-1)); z++) {
					temp = temp + " ";
				}
				for (int z = infix.length(); z > in_aft; z--) {
					temp[z + (swap * (-1))] = temp[z];
				}
				for (int z = 0; z < res.length(); z++) {
					temp[in_bef] = res[z];
					in_bef++;
				}
				infix = temp;
			}
			i = i - swap;
		}
	}
	return infix;
}

string string_cos_procedure(string infix) {
	for (int i = 0; i < infix.length(); i++) {

		if ((infix[i] == 'c') && (infix[i + 1] == 'o') && (infix[i + 2] == 's')) {
			string after;
			int j;
			j = i + 3;
			while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j < infix.length())) {
				after = after + infix[j];
				j++;
			}


			double b = 0;;

			one_string_to_double(b, after);


			double result;
			result = cos(b);
			string res = convertInt(result);
			int in_bef = i;
			int in_aft = i + after.length() + 2;
			int swap = (in_aft - in_bef + 1) - res.length();
			if (swap >= 0) {
				for (int z = 0; z < res.length(); z++) {
					infix[in_bef] = res[z];
					in_bef++;
				}
				if (swap != 0) {
					for (int g = 0; g < swap; g++) {
						for (int z = in_aft - swap + 1; z < infix.length(); z++) {
							infix[z] = infix[z + 1];
						}
					}
					string temp = "";
					for (int z = 0; z < infix.length() - swap; z++) {
						temp = temp + infix[z];
					}
					infix = temp;
				}
			}
			if (swap < 0) {
				string temp = infix;
				for (int z = 0; z < (swap * (-1)); z++) {
					temp = temp + " ";
				}
				for (int z = infix.length(); z > in_aft; z--) {
					temp[z + (swap * (-1))] = temp[z];
				}
				for (int z = 0; z < res.length(); z++) {
					temp[in_bef] = res[z];
					in_bef++;
				}
				infix = temp;
			}
			i = i - swap;
		}
	}
	return infix;
}
string string_sin_procedure(string infix) {
	for (int i = 0; i < infix.length(); i++) {

		if ((infix[i] == 's') && (infix[i + 1] == 'i') && (infix[i + 2] == 'n')) {
			string after;
			int j;
			j = i + 3;
			while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j < infix.length())) {
				after = after + infix[j];
				j++;
			}


			double b = 0;;

			one_string_to_double(b, after);


			double result;
			result = sin(b);
			string res = convertInt(result);
			int in_bef = i;
			int in_aft = i + after.length() + 2;
			int swap = (in_aft - in_bef + 1) - res.length();
			if (swap >= 0) {
				for (int z = 0; z < res.length(); z++) {
					infix[in_bef] = res[z];
					in_bef++;
				}
				if (swap != 0) {
					for (int g = 0; g < swap; g++) {
						for (int z = in_aft - swap + 1; z < infix.length(); z++) {
							infix[z] = infix[z + 1];
						}
					}
					string temp = "";
					for (int z = 0; z < infix.length() - swap; z++) {
						temp = temp + infix[z];
					}
					infix = temp;
				}
			}
			if (swap < 0) {
				string temp = infix;
				for (int z = 0; z < (swap * (-1)); z++) {
					temp = temp + " ";
				}
				for (int z = infix.length(); z > in_aft; z--) {
					temp[z + (swap * (-1))] = temp[z];
				}
				for (int z = 0; z < res.length(); z++) {
					temp[in_bef] = res[z];
					in_bef++;
				}
				infix = temp;
			}
			i = i - swap;
		}
	}
	return infix;
}
string string_ctg_procedure(string infix) {
	for (int i = 0; i < infix.length(); i++) {

		if ((infix[i] == 'c') && (infix[i + 1] == 't') && (infix[i + 2] == 'g')) {
			string after;
			int j;
			j = i + 3;
			while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j < infix.length())) {
				after = after + infix[j];
				j++;
			}


			double b = 0;;

			one_string_to_double(b, after);


			double result;
			result = 1 / tan(b);
			string res = convertInt(result);
			int in_bef = i;
			int in_aft = i + after.length() + 2;
			int swap = (in_aft - in_bef + 1) - res.length();
			if (swap >= 0) {
				for (int z = 0; z < res.length(); z++) {
					infix[in_bef] = res[z];
					in_bef++;
				}
				if (swap != 0) {
					for (int g = 0; g < swap; g++) {
						for (int z = in_aft - swap + 1; z < infix.length(); z++) {
							infix[z] = infix[z + 1];
						}
					}
					string temp = "";
					for (int z = 0; z < infix.length() - swap; z++) {
						temp = temp + infix[z];
					}
					infix = temp;
				}
			}
			if (swap < 0) {
				string temp = infix;
				for (int z = 0; z < (swap * (-1)); z++) {
					temp = temp + " ";
				}
				for (int z = infix.length(); z > in_aft; z--) {
					temp[z + (swap * (-1))] = temp[z];
				}
				for (int z = 0; z < res.length(); z++) {
					temp[in_bef] = res[z];
					in_bef++;
				}
				infix = temp;
			}
			i = i - swap;
		}
	}
	return infix;
}
string string_tg_procedure(string infix) {
	for (int i = 0; i < infix.length(); i++) {

		if ((infix[i] == 't') && (infix[i + 1] == 'g')) {
			string after;
			int j;
			j = i + 2;
			while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j < infix.length())) {
				after = after + infix[j];
				j++;
			}


			double b = 0;;

			one_string_to_double(b, after);


			double result;
			result = tan(b);
			string res = convertInt(result);
			int in_bef = i;
			int in_aft = i + after.length() + 1;
			int swap = (in_aft - in_bef + 1) - res.length();
			if (swap >= 0) {
				for (int z = 0; z < res.length(); z++) {
					infix[in_bef] = res[z];
					in_bef++;
				}
				if (swap != 0) {
					for (int g = 0; g < swap; g++) {
						for (int z = in_aft - swap + 1; z < infix.length(); z++) {
							infix[z] = infix[z + 1];
						}
					}
					string temp = "";
					for (int z = 0; z < infix.length() - swap; z++) {
						temp = temp + infix[z];
					}
					infix = temp;
				}
			}
			if (swap < 0) {
				string temp = infix;
				for (int z = 0; z < (swap * (-1)); z++) {
					temp = temp + " ";
				}
				for (int z = infix.length(); z > in_aft; z--) {
					temp[z + (swap * (-1))] = temp[z];
				}
				for (int z = 0; z < res.length(); z++) {
					temp[in_bef] = res[z];
					in_bef++;
				}
				infix = temp;
			}
			i = i - swap;
		}
	}
	return infix;
}
string string_ln_procedure(string infix) {
	for (int i = 0; i < infix.length(); i++) {

		if ((infix[i] == 'l') && (infix[i + 1] == 'n')) {
			string after;
			int j;
			j = i + 2;
			while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j < infix.length())) {
				after = after + infix[j];
				j++;
			}


			double b = 0;;

			one_string_to_double(b, after);


			double result;
			result = log(b);
			string res = convertInt(result);
			int in_bef = i;
			int in_aft = i + after.length() + 1;
			int swap = (in_aft - in_bef + 1) - res.length();
			if (swap >= 0) {
				for (int z = 0; z < res.length(); z++) {
					infix[in_bef] = res[z];
					in_bef++;
				}
				if (swap != 0) {
					for (int g = 0; g < swap; g++) {
						for (int z = in_aft - swap + 1; z < infix.length(); z++) {
							infix[z] = infix[z + 1];
						}
					}
					string temp = "";
					for (int z = 0; z < infix.length() - swap; z++) {
						temp = temp + infix[z];
					}
					infix = temp;
				}
			}
			if (swap < 0) {
				string temp = infix;
				for (int z = 0; z < (swap * (-1)); z++) {
					temp = temp + " ";
				}
				for (int z = infix.length(); z > in_aft; z--) {
					temp[z + (swap * (-1))] = temp[z];
				}
				for (int z = 0; z < res.length(); z++) {
					temp[in_bef] = res[z];
					in_bef++;
				}
				infix = temp;
			}
			i = i - swap;
		}
	}
	return infix;
}
string string_log_procedure(string infix) {
	for (int i = 0; i < infix.length(); i++) {

		if ((infix[i] == 'l') && (infix[i + 1] == 'o') && (infix[i + 2] == 'g')) {
			string after;
			int j;
			j = i + 3;
			while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j < infix.length())) {
				after = after + infix[j];
				j++;
			}


			double b = 0;;

			one_string_to_double(b, after);


			double result;
			result = log10(b);
			string res = convertInt(result);
			int in_bef = i;
			int in_aft = i + after.length() + 2;
			int swap = (in_aft - in_bef + 1) - res.length();
			if (swap >= 0) {
				for (int z = 0; z < res.length(); z++) {
					infix[in_bef] = res[z];
					in_bef++;
				}
				if (swap != 0) {
					for (int g = 0; g < swap; g++) {
						for (int z = in_aft - swap + 1; z < infix.length(); z++) {
							infix[z] = infix[z + 1];
						}
					}
					string temp = "";
					for (int z = 0; z < infix.length() - swap; z++) {
						temp = temp + infix[z];
					}
					infix = temp;
				}
			}
			if (swap < 0) {
				string temp = infix;
				for (int z = 0; z < (swap * (-1)); z++) {
					temp = temp + " ";
				}
				for (int z = infix.length(); z > in_aft; z--) {
					temp[z + (swap * (-1))] = temp[z];
				}
				for (int z = 0; z < res.length(); z++) {
					temp[in_bef] = res[z];
					in_bef++;
				}
				infix = temp;
			}
			i = i - swap;
		}
	}
	return infix;
}
string minus_plus_procedure(string infix) {
	string temp = "";
	for (int i = 0; i < infix.length() - 1; i++) {

		if ((infix[i] == '-') && (infix[i + 1] == '-')) {
			for (int j = 0; j < i; j++) {
				temp = temp + infix[j];
			}
			temp = temp + '+';
			for (int j = i + 2; j < infix.length(); j++) {
				temp = temp + infix[j];
			}
			i = i + 2;
		}

		if ((infix[i] == '-') && (infix[i + 1] == '+')) {
			for (int j = 0; j < i; j++) {
				temp = temp + infix[j];
			}
			temp = temp + '-';
			for (int j = i + 2; j < infix.length(); j++) {
				temp = temp + infix[j];
			}
			i = i + 2;
		}

		if ((infix[i] == '+') && (infix[i + 1] == '-')) {
			for (int j = 0; j < i; j++) {
				temp = temp + infix[j];

			}

			temp = temp + '-';
			for (int j = i + 2; j < infix.length(); j++) {
				temp = temp + infix[j];
			}
			i = i + 2;
		}

	}
	if (temp == "") return infix;
	return temp;
}
string string_brackets(string infix, int& brackets_open) {
	string res;
	if (brackets_open != 0) {
		int k = 0;
		int in_bef;
		int in_aft;

		for (int i = 0; i < infix.length(); i++) {
			if (infix[i] == '(') k++;
			if (k == brackets_open) {
				in_bef = i;
				int j = i + 1;
				while (infix[j] != ')') {
					res = res + infix[j];
					j++;
				}
				in_aft = j;

				res = string_sin_procedure(res);
				res = string_ln_procedure(res);
				res = string_ctg_procedure(res);
				res = string_tg_procedure(res);
				res = string_cos_procedure(res);

				res = string_power(res);

				res = string_multiplication(res);

				res = string_division(res);

				res = string_computation(res);

				res = string_addition(res);




				int swap = (in_aft - in_bef + 1) - res.length();
				if (swap >= 0) {
					for (int z = 0; z < res.length(); z++) {
						infix[in_bef] = res[z];
						in_bef++;
					}
					if (swap != 0) {
						for (int g = 0; g < swap; g++) {
							for (int z = in_aft - swap + 1; z < infix.length(); z++) {
								infix[z] = infix[z + 1];
							}
						}
						string temp = "";
						for (int z = 0; z < infix.length() - swap; z++) {
							temp = temp + infix[z];
						}
						infix = temp;
					}
				}
				if (swap < 0) {
					string temp = infix;
					for (int z = 0; z < (swap * (-1)); z++) {
						temp = temp + " ";
					}
					for (int z = infix.length(); z > in_aft; z--) {
						temp[z + (swap * (-1))] = temp[z];
					}
					for (int z = 0; z < res.length(); z++) {
						temp[in_bef] = res[z];
						in_bef++;
					}
					infix = temp;
				}


				brackets_open--;
			}
		}
	}
	return infix;
}
string implementation(string infix) {
	int a;
	int b;
	int brackets_open = 0;
	infix = string_exp(infix);
	infix = string_pi(infix);
	for (int i = 0; i < infix.length(); i++) {
		if (infix[i] == '(') brackets_open++;
	}





	int replay = brackets_open;
	for (int i = 0; i < replay; i++) {
		infix = string_brackets(infix, brackets_open);
	}
	

	infix = string_sin_procedure(infix);
	infix = string_ln_procedure(infix);
	infix = string_log_procedure(infix);
	infix = string_ctg_procedure(infix);
	infix = string_tg_procedure(infix);
	infix = string_cos_procedure(infix);
	infix = minus_plus_procedure(infix);

	for (int i = 0; i < 5; i++) {

		infix = string_power(infix);

		infix = string_multiplication(infix);

		infix = string_division(infix);



		infix = string_computation(infix);

		infix = string_addition(infix);

	}
	return infix;
}
