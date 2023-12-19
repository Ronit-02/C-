// Importing the required libraries.
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>

// using std::ios;
// using std::cout;
// using std::string;
// using std::vector;
// using std::fstream;
// using std::unordered_map;
// using std::priority_queue;

using namespace std;



// Tree for storing Huffman Tree
struct TreeNode {

    char character;
    int frequency;
    
    TreeNode *leftNode, *rightNode;
    
};


// Function that will create a new node of TreeNode type and also behaves as a constructor 
// to initialize values
TreeNode* getNewTreeNode(char character, int frequency, TreeNode* leftNode, TreeNode* rightNode) {
    
    TreeNode* newTreeNode = new TreeNode();

    newTreeNode->character = character;
    newTreeNode->frequency = frequency;

    newTreeNode->leftNode = leftNode;
    newTreeNode->rightNode = rightNode;
    // Initializes the left and right pointer for the tree.

    return newTreeNode;
}


// Comparator for the priority queue
struct comparator 
{
    // Overloading the () operator to compare the different values of two tree nodes
    bool operator()(TreeNode* leftNode, TreeNode* rightNode)
    {
        return leftNode->frequency > rightNode->frequency;
        // highest priority item has lowest frequency.
    }
};


// Function will calculate the huffman encoding for each character and 
// will store it in the unordered map
void huffmanEncoding(TreeNode* rootNode, string strEncode, unordered_map<char, string> &huffmanCodeMap)
{
    if (rootNode == nullptr)
    {
        return;
        // If the rootNode is empty
    }

    if(!rootNode->leftNode && !rootNode->rightNode)
    {
        huffmanCodeMap[rootNode->character] = strEncode;
        // If the node is the leaf node, then it will store the encoded string for 
        // the future reference in the unordered map.
    }

    huffmanEncoding(rootNode->leftNode, strEncode + "0", huffmanCodeMap);
    // Add a 0 in code for left node
    
    huffmanEncoding(rootNode->rightNode, strEncode + "1", huffmanCodeMap);
    // Add a 1 in code for Right node
}


// Function will build Huffman Tree, will store in unordered map, and will
// further build encoded message
string buildHuffmanTree(string plainText)
{
    unordered_map<char, int> frequencyMap;  
    // Unordered Map is used to store the frequency of each character.
    for(char ch: plainText) 
    {
        frequencyMap[ch]++;
    }
    //adding frequency char by char

    priority_queue<TreeNode*, vector<TreeNode*>, comparator> minFrequencyPriorityQueue;
    // Priority Queue is used for storing the leaf nodes of Huffman Tree.

    for(auto characterFrequencyPair: frequencyMap)
    {
        minFrequencyPriorityQueue.push(getNewTreeNode(characterFrequencyPair.first, characterFrequencyPair.second, nullptr, nullptr));
        // characterFrequencyPair: [ Character -> Frequency ]
    } 

    while(minFrequencyPriorityQueue.size() != 1) 
    {
        TreeNode *rightNode = minFrequencyPriorityQueue.top();
        minFrequencyPriorityQueue.pop();
        // Highest priority (min Freq) -> Right node -> removing it 

        TreeNode *leftNode = minFrequencyPriorityQueue.top();
        minFrequencyPriorityQueue.pop();
        // Highest priority (min Freq) -> left node -> removing it 

        int sumOfFrequency = leftNode->frequency + rightNode->frequency;
        // Creating the new INTERNAL NODE as sum of 2 frequencies

        minFrequencyPriorityQueue.push(getNewTreeNode('\0', sumOfFrequency, leftNode, rightNode));
        // Create a new node with the sumOfFrequencies and add it to the priority queue.
    }

    TreeNode* rootNode = minFrequencyPriorityQueue.top();
    // last node from priority queue treated as root node for encoding

    unordered_map<char, string> huffmanCodeMap;
    // Characters -> Huffman Code

    huffmanEncoding(rootNode, "", huffmanCodeMap);
    // To generate Encoding and storing the encoded message in the map

    cout<<"Huffman codes are : \n";
    for(auto characterCodePair: huffmanCodeMap) 
    {
        cout<<characterCodePair.first<<" -> "<<characterCodePair.second<<"\n";
        // Printing coded value of characters
    }

    string encodedMessage = "";   // to store encoded message

    for(char character: plainText)
    {
        encodedMessage += huffmanCodeMap[character];
        // Adding encoded message char by char from the map...
    }

    return encodedMessage;
}


// Function to read the contents and returns single string containing the entire content
string readPlainTextFile(string locationOfFile) 
{
    string fileText = "";
    // String to store Whole content of file
    
    string fileLine;
    // String to store the line read.

    fstream fileToBeEncoded;

    fileToBeEncoded.open(locationOfFile, ios::in);    // Opening file in read mode....

    if(fileToBeEncoded.is_open()) 
    {
        while(getline(fileToBeEncoded, fileLine))
        {
            if(fileText != "") 
            {
                fileText += "_";
            }
            fileText += fileLine;
        }
        // Reading in temp string and adding in new string

        fileToBeEncoded.close();    // File closing...
    }
    cout<<"\n\n"<<"Original message is : "<<"\n";
    cout<<fileText<<"\n\n";
    // Print the plain text in the file.

    return fileText;
}


// Function to write the encoded message to the file.
void writeToCompressedFile(string locationOfFile, string encodedMessage)
{
    cout<<"\n"<<"Encoded message is : \n";
    cout<<encodedMessage<<endl <<endl;

    fstream encodedFile;

    encodedFile.open(locationOfFile+".compressed", ios::binary | ios::out);    
    // ios::binary to ignore /n and /r, ios::out opens the file in write mode 
    
    if(encodedFile.is_open())
    {
        encodedFile<<encodedMessage;
        encodedFile.close();
    }

    return;
}


// Function to calculate the compression ratio and dump it on the screen.
void calculateCompressionRatio(string textString, string encodedString)
{
    double compressionRatio = 0.0;          // initializing it first to 0

    double originalSize = textString.length() * 8.0;    // converting it to bits

    double encodedSize = encodedString.length();

    compressionRatio = 100.0 - (encodedSize/originalSize*100);

    cout<<"Compression ratio for the current encoding is : "<<compressionRatio<<"%"<<"\n\n";

    return;
}


int main() 
{
    string fileName;

    cout<<"\n\t====================================";
	cout<<"\n\t\t  File Zipper   \n";
	cout<<"\t====================================";
	cout<<"\n\nEnter name of file to compress: ";
	
    cin >> fileName;
    fileName += ".txt";

    string textString = readPlainTextFile(fileName);        //  input from file.

    string encodedString = buildHuffmanTree(textString);    // Encoding String

    writeToCompressedFile(fileName, encodedString);        // Storing encoded message
 
    calculateCompressionRatio(textString, encodedString);  // Calculate Compression Ratio

    cout << fileName << ".compressed has been created successfully";
    
    return 0;
}