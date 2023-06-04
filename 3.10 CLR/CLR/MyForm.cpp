#include "MyForm.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace System;
using namespace System::Windows::Forms;

namespace CLR {
    // ������� ��� �����������, �������� �� ������ �������
    bool is_vowel(char c) {
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    // ������� ��� ����������� ���� ������� � �����
    double vowel_ratio(const std::string& word) {
        int len = word.length();
        int vowel_count = count_if(word.begin(), word.end(), is_vowel);
        return vowel_count;
    }

    // ������� ��� ���������� ����� � ������������ ����� �������
    std::string MyForm::find_max_vowel_word(const std::string sentence) {
        std::string max_word;
        double max_ratio = 0.0;
        std::vector<std::string> words;

        // ���������� ����������� �� �����
        std::string word;
        for (char c : sentence) {
            if (isspace(c)) {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            }
            else {
                word += c;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        // ����� ����� � ������������ ����� �������
        for (std::string w : words) {
            double ratio = vowel_ratio(w);
            if (ratio >= max_ratio) {
                max_ratio = ratio;
                max_word = w;
            }
        }

        return max_word;
    }

}
[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    CLR::MyForm form;
    Application::Run(% form);
}