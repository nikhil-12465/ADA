#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>

using namespace std;


set<string> common_words = {"is", "am", "are", "was", "were", "be", "been", "being", 
                         "have", "has", "had", "having", "do", "does", "did", 
                         "a", "an", "the","and","of","on","in","to","with","for","it","at"};


vector<string> create_vector_from_file(const string& filename) {              // function for read from file and created the vector
    vector<string> words;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Could not open the file " << filename << endl;
        return ;  
    }

    string word;
    while (file >> word) {
    
        transform(word.begin(), word.end(), word.begin(), ::tolower);             // Convert each word  to lowercase 
        
        
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());   // remove the pantuations if any exits 

       
        if (common_words.find(word) == common_words.end()) {                       // skip that are the common words 
            words.push_back(word);  
        }
    }

    file.close(); 
    return words;
}


vector<int> create_word_frequency_vector(const vector<string>& words, const set<string>& uniqueWords) {            // function  for creation of the word frequency vector which is used for find the frequency of the unique words and make their vector 
    vector<int> wordFreq(uniqueWords.size(), 0);

   for (const string& word : words) {
   
    if (uniqueWords.count(word) > 0) {
       
        size_t index = 0;
        for (const string& uniqueWord : uniqueWords) {
            if (uniqueWord == word) {
                wordFreq[index]++;
                break;  
            }
            index++;
        }
    }
}


    return wordFreq;
}


double cosine_similarity(const vector<int>& vec1, const vector<int>& vec2) {     // function for the cosine similarity 
    double dotProd = 0.0;
    double magVec1 = 0.0;
    double magVec2 = 0.0;


    for (size_t i = 0; i < vec1.size(); ++i) {
        dotProd += vec1[i] * vec2[i];
        magVec1 += vec1[i] * vec1[i];
        magVec2 += vec2[i] * vec2[i];
    }

    return dotProd / (sqrt(magVec1) * sqrt(magVec2));
}



int main() {
    string file1 = "vector1.txt"; 
    string file2 = "vector2.txt";  

   
    vector<string> words1 = create_vector_from_file(file1);
    vector<string> words2 = create_vector_from_file(file2);

   
    set<string> uniqueWords;
    uniqueWords.insert(words1.begin(), words1.end());                    // Create a set of unique words in both files
    uniqueWords.insert(words2.begin(), words2.end());


    vector<int> freqVector1 = create_word_frequency_vector(words1, uniqueWords);
    vector<int> freqVector2 = create_word_frequency_vector(words2, uniqueWords);

   
    double similarity = cosine_similarity(freqVector1, freqVector2);           // calculate the similarity between the two frequency vectors 

 
    cout << "Cosine Similarity between the vectors: " << similarity << endl;

    return 0;
}
