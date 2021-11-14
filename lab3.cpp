#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace::std;

class text_manipulation {

public:

    int count_sentence (string text) {

        int nr_sentence = 0;
        for (int i = 0; text[i]; i++)
            if (text[i] == '.' || text[i] == '?' || text[i] == '!')
                nr_sentence++;
        return nr_sentence; }

    int count_words (string text) {

        int nr_words = 1;
        for (int i = 0; text[i]; i++)
            if (isspace (text[i]) )
                nr_words++;
        return nr_words; }

    int count_letters (string text) {

        int nr_letters = 0;
        for (int i = 0; text[i]; i++)
            if (isalpha (text[i]) )
                nr_letters++;

        return nr_letters; }

    int count_vowels (string text) {

        int nr_vowels = 0;
        for (int i = 0; text[i]; i++)
            if (strchr ("aeiouAEIOU", text[i]) )
                nr_vowels++;

        return nr_vowels; }

    int count_consonants (string text) {

        int nr_consonants = 0;
        for (int i = 0; text[i]; i++)
            if (!strchr ("aeiouAEIOU", text[i]) && isalpha (text[i]) )
                nr_consonants++;

        return nr_consonants; }

    void top_5 (string text) {

        transform (text.begin (), text.end (), text.begin (), ::tolower);

        for (size_t i = 0, len = text.size (); text[i]; i++)
            if (ispunct (text[i]) ) {
                text.erase (i--, 1);
                len = text.size (); }

        map <string, int> freq;
        string word_holder, longest_word;
        unsigned long max = 0;

        for (int i = 0; text[i]; i++) {

            if (isspace (text[i]) ) {

                if (word_holder.size () > max) {
                    max = word_holder.size ();
                    longest_word = word_holder;
                }

                if (freq.count (word_holder) == 0) {
                    freq[word_holder] = 1;
                    word_holder = "";
                }

                else {
                    freq[word_holder]++;
                    word_holder = "";
                }
            }

            else { word_holder += text[i]; }
        }

        multimap <int, string> freq_sort;
        for (auto &i : freq)
            freq_sort.insert ({ i.second, i.first });

        multimap <int, string> ::reverse_iterator it = freq_sort.rbegin ();

        for (int j = 0; it != freq_sort.rend () && j < 5; j++, it++)
            cout << it -> second << " " << it -> first << endl;

        cout << endl << "Longest Word : " << longest_word << endl << endl; }
};

int main () {

    text_manipulation obj;
    string text ("Humans (Homo sapiens) are the most abundant and widespread species of primate, characterized by bipedality, large and complex brains enabling the development of advanced tools, culture and language. Humans are highly social beings and tend to live in complex social structures composed of many cooperating and competing groups, from families and kinship networks to political states. Social interactions between humans have established a wide variety of values, social norms, and rituals, which bolster human society. Curiosity and the human desire to understand and influence the environment and to explain and manipulate phenomena have motivated humanity's development of science, philosophy, mythology, religion, and other fields of knowledge.");

    cout << "Number of Sentences : " << obj.count_sentence (text) << endl;
    cout << "Number of Words : " << obj.count_words (text) << endl;
    cout << "Number of Letters : " << obj.count_letters (text) << endl;
    cout << "Number of Vowels : " << obj.count_vowels (text) << endl;
    cout << "Number of Consonants : " << obj.count_consonants (text) << endl << endl;
    cout << "The most often words in the text (top 5): " << endl;
    obj.top_5 (text);

    return 0; }
