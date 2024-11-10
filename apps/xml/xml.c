// xml.c
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

void parsePerson(xmlNode *node) {
    xmlNode *cur_node = NULL;
    for (cur_node = node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            if (xmlStrcmp(cur_node->name, (const xmlChar *)"Name") == 0) {
                printf("Name: %s\n", xmlNodeGetContent(cur_node));
            } else if (xmlStrcmp(cur_node->name, (const xmlChar *)"Age") == 0) {
                printf("Age: %s\n", xmlNodeGetContent(cur_node));
            } else if (xmlStrcmp(cur_node->name, (const xmlChar *)"Height") == 0) {
                printf("Height: %s cm\n", xmlNodeGetContent(cur_node));
            }
        }
        parsePerson(cur_node->children);
    }
}

int main() {
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    // Parse the XML file
    doc = xmlReadFile("person.xml", NULL, 0);
    if (doc == NULL) {
        printf("Error: could not parse file person.xml\n");
        return 1;
    }

    // Get the root element node
    root_element = xmlDocGetRootElement(doc);
    parsePerson(root_element);

    // Free the document
    xmlFreeDoc(doc);
    xmlCleanupParser();

    return 0;
}
