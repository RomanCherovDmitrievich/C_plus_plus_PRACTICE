#include <iostream>
#include <vector>
#include <string>

// Базовый компонент (интерфейс)
class FileSystemComponent {
public:
    virtual ~FileSystemComponent() = default;
    virtual void display(int depth = 0) const = 0;
    virtual void add(FileSystemComponent* component) {
        std::cout << component << std::endl;
        throw std::runtime_error("Не удается добавить к листу!");
    };
};

// Лист (файл)
class File : public FileSystemComponent {
private:
    std::string name;
public:
    File(const std::string& name) : name(name) {}
    void display(int depth = 0) const override {
        std::string str_depth = std::to_string(depth);
        std::cout << str_depth << "📄 " << name << std::endl;
    }
};

// Узел (директория)
class Directory : public FileSystemComponent {
private:
    std::string name;
    std::vector<FileSystemComponent*> children;
public:
    Directory(const std::string& name) : name(name) {}
    void add(FileSystemComponent* component) override {
        children.push_back(component);
    }
    void display(int depth = 0) const override {
        std::string str_depth = std::to_string(depth);
        std::cout << str_depth << "📁 " << name << std::endl;
        for (const auto& child : children) {
            child->display(depth + 1);
        }
    }
    ~Directory() {
        for (auto child : children) {
            delete child;
        }
    }
};

int main() {

    Directory* root = new Directory("root");
    Directory* documents = new Directory("documents");
    Directory* images = new Directory("images");

    File* resume = new File("resume.txt");
    File* photo = new File("photo.jpg");
    File* notes = new File("notes.txt");

    documents->add(resume);
    images->add(photo);

    root->add(documents);
    root->add(images);
    root->add(notes);

    root->display();

    delete root;
    return 0;
}