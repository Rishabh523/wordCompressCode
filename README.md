# Execution Steps

Clone the repo into your local pc.

Open it into your visual studio editor.

Run the file solution.cpp(c++ compiler must be installed in your pc).

Input files must be in the same folder.

Output will print in the console.

Change input file name (input_01.txt or input_02.txt) as required in program.


# Approach and Algorithm
The algorithm for the solution :

Step 1. Build the trie by reading every word one by one from the selected file.

Step 2. While building the trie also build a queue which contains <word,suffix> pairs if any w.r.t the previously existing valid words in the trie.

Step 3. Initialize the longest, seclongest, and maxlength variables.

Step 4. Repeat until the queue is empty, POP the <word,suffix> pairs from the queue.

i) Check if the suffix of the word contains any valid word i.e. prefix from the trie and if length (word) > maxlength , set seclongest = longest , longest = word and maxlength = length(word).

ii) Else get all the prefixes of the current suffix of the word , and find the new suffixes w.r.t each and every prefix length. Append the new <word,suffix> pairs into the deque.

Step 5. Return the longest and seclongest words

# Overview

-> The program reads a list of words from an input file, processes them, and then outputs the longest and second longest compound words found in the list. It also measures the time taken to complete the task.

Trie Data Structure
The program employs a trie data structure to efficiently store and search for words. A trie is a tree-like structure in which each node represents a character in a word. The tree starts at the root node and branches into child nodes, each corresponding to a different character. The Trie class includes methods for inserting words into the trie and searching for words.
