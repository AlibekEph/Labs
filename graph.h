#include <stddef.h>
#include <iostream>
template<typename ValueType, typename KeyType, typename WeightType>
class Graph {
public:
    using value_type = ValueType;
    using key_type = KeyType;
    using weight_type = WeightType;
    // Конструкторы
    Graph();
    Graph(const Graph& other);
    Graph(Graph&& other);

    // Операторы присваивания
    Graph& operator=(const Graph& other);
    Graph& operator=(Graph&& other);

    
    class Node {
    public:
        using value_type = ValueType;
        using key_type = KeyType;
        using weight_type = WeightType;
        // Конструкторы
        Node();
        Node(const value_type& value);
        Node(value_type&& value);
        Node(const Node& other);
        Node(Node&& other);

        // Операторы присваивания
        Node& operator=(const Node& other);
        Node& operator=(Node&& other);

        // Методы
        bool empty() const;
        size_t size() const;
        value_type& value();
        const value_type& value() const;
        void clear();

        // Итераторы
        using iterator = typename std::unordered_map<key_type, weight_type>::iterator;
        using const_iterator = typename std::unordered_map<key_type, weight_type>::const_iterator;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;

    private:
        value_type value_;
        std::unordered_map<key_type, weight_type> edges_;
    };

    // Методы
    bool empty() const;
    size_t size() const;
    void clear();
    void swap(Graph& other);

    // Итераторы
    using iterator = typename std::unordered_map<key_type, Node>::iterator;
    using const_iterator = typename std::unordered_map<key_type, Node>::const_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;

    // Работа с графом через ключ
    value_type& operator[](const key_type& key);
    value_type& at(const key_type& key);

    // Методы работы с узлами
    size_t degree_in(const key_type& key) const;
    size_t degree_out(const key_type& key) const;
    bool loop(const key_type& key) const;

private:
    std::unordered_map<key_type, Node> nodes;
};