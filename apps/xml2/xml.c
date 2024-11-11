#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

// Global variables
char title[50];
char editor[50];
char isbn[20];
int yearOfPublication;
int numberOfPages;

// Function to parse the book's data from the XML file
void parseBook(const char *filename) {
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    // Parse the XML file
    doc = xmlReadFile(filename, NULL, 0);
    if (doc == NULL) {
        printf("Error: could not parse file %s\n", filename);
        return;
    }

    // Get the root element node
    root_element = xmlDocGetRootElement(doc);

    // Traverse the XML tree
    for (xmlNode *node = root_element->children; node; node = node->next) {
        if (node->type == XML_ELEMENT_NODE) {
            if (xmlStrcmp(node->name, (const xmlChar *)"Title") == 0) {
                snprintf(title, sizeof(title), "%s", xmlNodeGetContent(node));
            } else if (xmlStrcmp(node->name, (const xmlChar *)"Editor") == 0) {
                snprintf(editor, sizeof(editor), "%s", xmlNodeGetContent(node));
            } else if (xmlStrcmp(node->name, (const xmlChar *)"ISBN") == 0) {
                snprintf(isbn, sizeof(isbn), "%s", xmlNodeGetContent(node));
            } else if (xmlStrcmp(node->name, (const xmlChar *)"YearOfPublication") == 0) {
                yearOfPublication = atoi((char *)xmlNodeGetContent(node));
            } else if (xmlStrcmp(node->name, (const xmlChar *)"NumberOfPages") == 0) {
                numberOfPages = atoi((char *)xmlNodeGetContent(node));
            }
        }
    }

    // Free the document
    xmlFreeDoc(doc);
    xmlCleanupParser();
}

int main() {
    // Parse the book data from the XML file
    parseBook("book.xml");

    // Print the book's data
    printf("Title: %s\n", title);
    printf("Editor: %s\n", editor);
    printf("ISBN: %s\n", isbn);
    printf("Year of Publication: %d\n", yearOfPublication);
    printf("Number of Pages: %d\n", numberOfPages);

    return 0;
}

