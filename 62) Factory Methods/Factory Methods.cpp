#include <iostream>
#include <string>
#include <memory>

using namespace std;

//FACTORY METHOD :
//A Factory Method is a design pattern that focuses on decoupling the process of object
//creation from the code that uses the object.
//It provides an interface (usually a class) for creating an object, but allows subclasses
//to decide which class to instantiate. The goal is to let a class defer the instantiation logic to its children.



// ==== 4 MAIN COMPONENTS OF FACTORY METHOD ====

//1) Product (Interface): The base class for the objects being created (e.g., Document).

//2) Concrete Product: The actual classes instantiated by the factory (e.g., WordDocument, PdfDocument).

//3) Creator (Interface): The base class that declares the Factory Method (e.g., DocumentApp).

//4) Concrete Creator: The subclasses that implement the Factory Method to produce a specific concrete product (e.g., WordApp, PdfApp).



// === 1. Product Interface (Document) ===
class Document
{
public:
    virtual ~Document() = default;
    virtual void open() const = 0;
    virtual void print() const = 0;
};

// === 2. Concrete Products (Text and HTML Documents) ===
class TextDocument : public Document
{
public:
    void open() const override
    {
        cout << "TextDocument opened: Ready for basic word processing." << endl;
    }
    void print() const override
    {
        cout << "TextDocument printing on standard printer." << endl;
    }
};

class HtmlDocument : public Document
{
public:
    void open() const override
    {
        cout << "HtmlDocument opened: Ready for browser rendering." << endl;
    }
    void print() const override
    {
        cout << "HtmlDocument printing with web layout adjustments." << endl;
    }
};

// ---

// === 3. Creator/Factory Interface (DocumentProcessor) ===
class DocumentProcessor
{
public:
    virtual ~DocumentProcessor() = default;

    // The Factory Method: Creates and returns a Document object.
    virtual unique_ptr<Document> createDocument() const = 0;

    // Common Processing Logic (uses the product created by the factory method)
    void process() const
    {
        unique_ptr<Document> doc = this->createDocument();
        cout << "--- Starting document workflow ---" << endl;
        doc->open();
        doc->print();
        cout << "--- Workflow finished ---" << endl;
    }
};

// === 4. Concrete Creators/Factories ===
class TextProcessor : public DocumentProcessor
{
public:
    // Factory Method implementation for creating a TextDocument
    unique_ptr<Document> createDocument() const override
    {
        return make_unique<TextDocument>();
    }
};

class HtmlProcessor : public DocumentProcessor
{
public:
    // Factory Method implementation for creating an HtmlDocument
    unique_ptr<Document> createDocument() const override
    {
        return make_unique<HtmlDocument>();
    }
};

// ---

int main()
{
    cout << "Factory Method: Document Processor Example" << endl;

    // Use the Text Processor factory
    unique_ptr<DocumentProcessor> text_processor = make_unique<TextProcessor>();
    text_processor->process();

    cout << "\n======================================" << endl;

    // Use the HTML Processor factory
    unique_ptr<DocumentProcessor> html_processor = make_unique<HtmlProcessor>();
    html_processor->process();

    return 0;
}














//By using Raw Pointers (Issues of Memory Leak)

/*
// 1. Product Interface
class Logger
{
public:
    virtual ~Logger() {} // Crucial: virtual destructor for proper cleanup
    virtual void log(const std::string& message) const = 0;
};

// 2. Concrete Product (Example)
class ConsoleLogger : public Logger
{
public:
    void log(const std::string& message) const override
    {
        // ... logging implementation
    }
};

// 3. Creator/Factory Interface
class LoggerFactory
{
public:
    virtual ~LoggerFactory() {}

    // The Factory Method: Returns a raw pointer to the base class type.
    virtual Logger* createLogger() const = 0;

    // Core Business Logic
    void performLoggingTask() const
    {
        // ⚠️ The ownership of this object is now a manual responsibility
        Logger* logger = this->createLogger();

        logger->log("Task started.");

        // ⚠️ MANUAL CLEANUP IS REQUIRED!
        delete logger;
    }
};

// 4. Concrete Creator (Example)
class ConsoleLoggerFactory : public LoggerFactory
{
public:
    // Implements the Factory Method
    Logger* createLogger() const override
    {
        return new ConsoleLogger(); // Instantiates a concrete product
    }
};
*/








