#include "int_list_t.h"

int_list_t::int_list_t() {
    front_custom = new node_t(0, nullptr, nullptr);
    back_custom = new node_t(0, nullptr, front_custom);
    front_custom->next = back_custom;
    len = 0;
}

int_list_t::node_t *int_list_t::get(int position) const {
    if (position <= len / 2) {
        node_t *current = front_custom->next;
        while (position > 0) {
            current = current->next;
            position -= 1;
        }

        return current;
    } else {
        node_t *current = back_custom;
        while (position < len) {
            current = current->prev;
            position+=1;
        }

        return current;
    }
}

int_list_t::int_list_t(const int_list_t &list) : int_list_t() {
    len = list.len;
    auto current = list.front_custom->next;
    while (current != list.back_custom) {
        push_back(current->value);
        current = current->next;
    }
}

void int_list_t::insert(size_t position, int value) {
    node_t *current = get(position);
    node_t *new_node = new node_t(value, current, current->prev);
    current->prev->next = new_node;
    current->prev = new_node;
    len+=1;
}

void int_list_t::push_front(int value) {
    insert(0, value);
}

void int_list_t::push_back(int value) {
    insert(len, value);
}

void int_list_t::swap(int_list_t &list) {
    std::swap(front_custom, list.front_custom);
    std::swap(back_custom, list.back_custom);
    std::swap(len, list.len);
}


int_list_t::int_list_t(size_t count, int value) : int_list_t() {
    for (int i = 1; i < count; ++i) {
        push_back(value);
    }
}

int_list_t::~int_list_t() {
    clear();
    delete front_custom;
    delete back_custom;
}

int_list_t &int_list_t::operator=(const int_list_t &list) {
    int_list_t current(list);
    swap(current);
    return *this;
}

int &int_list_t::operator[](size_t position) {
    node_t *current = get(position);
    return current->value;
}

const int &int_list_t::operator[](size_t position) const {
    node_t *pointer = get(position);
    return pointer->value;
}

int &int_list_t::back() {
    return back_custom->prev->value;
}

const int int_list_t::back() const {
    return back_custom->prev->value;
}

int &int_list_t::front() {
    return front_custom->next->value;
}

const int int_list_t::front() const {
    return front_custom->next->value;
}

size_t int_list_t::size() const {
    return len;
}

int_list_t int_list_t::splice(size_t start_position, size_t count) {
    int_list_t result = int_list_t();
    node_t *temp = get(start_position);
    result.front_custom = temp -> prev;
    for (size_t i = 0; i < count; i++) {
        temp = temp->next;
    }
    result.back_custom = temp->next;
    result.front_custom->prev->next = result.back_custom->next;
    result.back_custom->next->prev = result.front_custom->prev;
    result.front_custom->prev = nullptr;
    result.back_custom->next = nullptr;
    result.len = count;
    len -= count;
    return result;

}
bool int_list_t::empty() const {
    return (len == 0);
}

void int_list_t::clear() {
    node_t *current = front_custom->next;
    node_t *next_node = current->next;
    while (next_node != back_custom) {
        delete (current);
        current = next_node;
        next_node = current->next;
    }
    len = 0;
}


void int_list_t::erase(size_t position) {
    node_t *current = get(position);
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    len -= 1;
}

void int_list_t::pop_front() {
    erase(0);
}

void int_list_t::pop_back() {
    erase(len - 1);
}



int_list_t &int_list_t::merge(int_list_t &list) {
    if (!list.empty()) {
        back_custom->prev->next = list.front_custom->next;
        list.front_custom->next->prev = back_custom->prev;
        list.back_custom->prev->next = back_custom;
        back_custom->prev = list.back_custom->prev;

        list.front_custom->next = list.back_custom;
        list.back_custom->prev = list.front_custom;
        len += list.len;
        list.len = 0;
    }

    return *this;
}

void int_list_t::reverse() {
    if (!empty()) {
        node_t *current = front_custom->next;
        node_t *next_node = current->next;
        while (next_node != back_custom) {
            std::swap(current->next, current->prev);
            current = next_node;
            next_node = current->next;
        }
        front_custom->next->prev = front_custom;
        back_custom->prev->next = back_custom;
        std::swap(front_custom->next, back_custom->prev);
    }
    reversed = std::abs(reversed - 1);
}

std::istream &operator>>(std::istream &stream, int_list_t &list) {
    int value = 0;
    list.clear();
    while (stream >> value) {
        list.push_back(value);
    }
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const int_list_t &list) {
    auto current = list.front_custom->next;
    while (current != list.back_custom) {
        stream << current->value << " ";
        current = current->next;
    }
    return stream;
}