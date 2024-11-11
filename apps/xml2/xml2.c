#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

char completeBookData[220];
char title[50];
char editor[50];
char isbn[20];
int yearOfPublication;
int numberOfPages;

void parseBook(xmlNode *node) {
    xmlNode *cur_node = NULL;
    for (cur_node = node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            if (xmlStrcmp(cur_node->name, (const xmlChar *)"Title") == 0) {
                snprintf(title, sizeof(title), "%s", xmlNodeGetContent(cur_node));
            } else if (xmlStrcmp(cur_node->name, (const xmlChar *)"Editor") == 0) {
                snprintf(editor, sizeof(editor), "%s", xmlNodeGetContent(cur_node));
            } else if (xmlStrcmp(cur_node->name, (const xmlChar *)"ISBN") == 0) {
                snprintf(isbn, sizeof(isbn), "%s", xmlNodeGetContent(cur_node));
            } else if (xmlStrcmp(cur_node->name, (const xmlChar *)"YearOfPublication") == 0) {
		yearOfPublication = atoi((char *)xmlNodeGetContent(cur_node));
	    } else if (xmlStrcmp(cur_node->name, (const xmlChar *)"NumberOfPages") == 0) {
		numberOfPages = atoi((char *)xmlNodeGetContent(cur_node));
	    }

        }
        parseBook(cur_node->children);
    }
}

int main() {
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    // Parse the XML file
    doc = xmlReadFile("book.xml", NULL, 0);
    if (doc == NULL) {
        printf("Error: could not parse file person.xml\n");
        return 1;
    }

    // Get the root element node
    root_element = xmlDocGetRootElement(doc);
    parseBook(root_element);

    snprintf(completeBookData, sizeof(completeBookData),
	"Title: %s\n"
	"Editor: %s\n"
	"ISBN: %s\n"
	"Year: %d\n"
	"Pages: %d\n", 
	title, editor, isbn, yearOfPublication, numberOfPages);	
    printf("%s", completeBookData);

    // Free the document
    xmlFreeDoc(doc);
    xmlCleanupParser();

    return 0;
}
