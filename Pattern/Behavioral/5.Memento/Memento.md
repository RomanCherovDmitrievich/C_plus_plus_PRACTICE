# 5. Memento (Снимок)
__Суть:__
Позволяет сохранять и восстанавливать предыдущее состояние объекта без раскрытия его внутренней структуры.

## Пример
```c++
#include <iostream>
#include <string>

// Объект, состояние которого нужно сохранять
class Editor {
    std::string text;
public:
    void setText(const std::string& s) { text = s; }
    std::string getText() const { return text; }

    // Создает снимок текущего состояния
    class Memento {
        std::string state;
        friend class Editor;
        Memento(const std::string& s) : state(s) {}
    public:
        std::string getState() const { return state; }
    };

    Memento createMemento() const { return Memento(text); }
    void restoreFromMemento(const Memento& m) { text = m.getState(); }
};

// Опекун (Caretaker) управляет снимками
class History {
    std::vector<Editor::Memento> mementos;
public:
    void push(const Editor::Memento& m) { mementos.push_back(m); }
    Editor::Memento pop() {
        if (mementos.empty()) throw std::runtime_error("No mementos");
        auto m = mementos.back();
        mementos.pop_back();
        return m;
    }
};

int main() {
    Editor editor;
    History history;

    editor.setText("Version 1");
    history.push(editor.createMemento());

    editor.setText("Version 2");
    std::cout << "Current: " << editor.getText() << std::endl;  // Version 2

    editor.restoreFromMemento(history.pop());
    std::cout << "Restored: " << editor.getText() << std::endl;  // Version 1

    return 0;
}
```
## Плюсы:
✅ Сохраняет инкапсуляцию (не раскрывает детали объекта).
✅ Позволяет откатывать состояния (undo/redo).

## Минусы:
❌ Может потреблять много памяти при частых сохранениях.

## Где применяется?
1. Текстовые редакторы (Ctrl+Z).
2. Игры (сохранение позиции игрока).
3. Транзакции в БД.