#include <iostream>

using namespace std;

class TrieNode
{
public:
  TrieNode *child[26];
  int ew;
  int cp;

  TrieNode()
  {
    for (int i = 0; i < 26; i++)
    {
      child[i] = NULL;
    }
    ew = 0;
    cp = 0;
  }

  bool isExist(char ch)
  {
    return child[ch - 'a'] != nullptr;
  }

  TrieNode *get(char ch)
  {
    return child[ch - 'a'];
  }

  void put(char ch, TrieNode *node)
  {
    child[ch - 'a'] = node;
  }

  void setEndWord()
  {
    ew = ew + 1;
  }

  void setCountPrefix()
  {
    cp = cp + 1;
  }

  void reduceEndWord()
  {
    ew = ew - 1;
  }

  void reduceCountPrefix()
  {
    cp = cp - 1;
  }
};

class Trie
{
private:
  TrieNode *root;

public:
  Trie()
  {
    root = new TrieNode();
  }

  void insert(string word)
  {
    TrieNode *node = root;
    for (int i = 0; i < word.size(); i++)
    {
      if (!node->isExist(word[i]))
      {
        TrieNode *newNode = new TrieNode();
        node->put(word[i], newNode);
      }
      node = node->get(word[i]);
      node->setCountPrefix();
    }
    node->setEndWord();
  }

  int wordFrequency(string word)
  {
    TrieNode *node = root;
    for (int i = 0; i < word.size(); i++)
    {
      if (!node->isExist(word[i]))
      {
        return 0;
      }
      node = node->get(word[i]);
    }
    return node->ew;
  }

  int startsWithWord(string word)
  {
    TrieNode *node = root;
    for (int i = 0; i < word.size(); i++)
    {
      if (!node->isExist(word[i]))
      {
        return 0;
      }
      node = node->get(word[i]);
    }
    return node->cp;
  }

  void deleteWord(string word)
  {
    TrieNode *node = root;
    for (int i = 0; i < word.size(); i++)
    {
      if (!node->isExist(word[i]))
      {
        return;
      }
      node = node->get(word[i]);
      node->reduceCountPrefix();
    }
    node->reduceEndWord();
  }
};

int main()
{
  Trie *newTrie = new Trie();

  newTrie->insert("apple");
  newTrie->insert("apple");
  newTrie->insert("apps");
  newTrie->insert("apps");
  newTrie->insert("khateeb");
  newTrie->insert("zoya");

  cout << "Frequency of apple is " << newTrie->wordFrequency("apple") << endl;

  cout << "Starts with app is " << newTrie->startsWithWord("app") << endl;

  newTrie->deleteWord("apple");

  cout << "Frequency of apple is " << newTrie->wordFrequency("apple") << endl;

  return 0;
}