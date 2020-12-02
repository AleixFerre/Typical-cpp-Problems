/*
    Aleix Ferré | https://github.com/CatalaHD
    -----------------------------------------

    Programa que calcula si una seqüència de parèntesis és vàlida
    Això vol dir que cada parèntesis que s'obre es tanca abans d'obrir-ne un altre d'igual
    i abans d'acabar la seqüència (tots els que s'obren es tanquen).
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;


bool seqCorrecta(const string& s) {
    stack<char> chars; // Pila de caràcters per guardar a qui li correspon cada parèntesis
    bool correcte = true;

    for (unsigned i = 0; i < s.size(); i++) {
        char actual = s[i];
        if (actual == '[' or actual == '(' or actual == '{') {
            // Obrim
            chars.push(actual);
        } else if (actual == ']' or actual == ')' or actual == '}') {
            // Tanquem
            if (chars.empty()) { // Si està buida, no comprovem res, per que sabem que està malament
                correcte = false;
                break;
            } else { // Si no està buida, traiem l'ultim element
                char obert = chars.top();
                chars.pop();
                if (not((obert == '(' and actual == ')') or
                        (obert == '[' and actual == ']') or
                        (obert == '{' and actual == '}'))) {
                    correcte = false;
                    break;
                }
            }
        } else { // Un altre caràcter no vàlid a la sequència
            correcte = false;
            break;
        }
    }

    if (chars.size() != 0) // Si ens queda algun parèntesis per tancar al final del string, també està malament!
        correcte = false;

    return correcte;
}

int main() {
    vector<string> sequencies = {"[()]{}{[()()]()}", "{[[]()]", "{[[](])}", "[a]"};

    for (string s : sequencies) {
        bool correcte = seqCorrecta(s);
        cout << s << endl << "La sequencia es " << string(correcte ? "correcta :)" : "incorrecta :(") << endl << "=============" << endl;
    }

    return 0;
}
