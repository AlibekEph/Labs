#include <unordered_map>
#include <stdexcept>

// Конструкторы
Graph::Graph() {}

Graph::Graph(const Graph& other) : nodes(other.nodes) {}

Graph::Graph(Graph&& other) noexcept : nodes(std::move(other.nodes)) {}

// Операторы присваивания
Graph& Graph::operator=(const Graph& other) {
    if (this != &other) {
        nodes = other.nodes;
    }
    return *this;
}

Graph& Graph::operator=(Graph&& other) noexcept {
    if (this != &other) {
        nodes = std::move(other.nodes);
    }
    return *this;
}

// Методы
bool Graph::empty() const {
    return nodes.empty();
}

size_t Graph::size() const {
    return nodes.size();
}

void Graph::clear() {
    nodes.clear();
}

void Graph::swap(Graph& other) {
    nodes.swap(other.nodes);
}

// Итераторы
typename Graph::iterator Graph::begin() {
    return nodes.begin();
}

typename Graph::iterator Graph::end() {
    return nodes.end();
}

typename Graph::const_iterator Graph::begin() const {
    return nodes.begin();
}

typename Graph::const_iterator Graph::end() const {
    return nodes.end();
}

typename Graph::const_iterator Graph::cbegin() const {
    return nodes.cbegin();
}

typename Graph::const_iterator Graph::cend() const {
    return nodes.cend();
}

// Работа с графом через ключ
value_type& Graph::operator[](const key_type& key) {
    return nodes[key].value();
}

value_type& Graph::at(const key_type& key) {
    try {
        return nodes.at(key).value();
    } catch (const std::out_of_range& e) {
        throw std::runtime_error("Node with key '" + key + "' does not exist in the graph.");
    }
}

// Методы работы с узлами
size_t Graph::degree_in(const key_type& key) const {
    if (nodes.count(key) == 0) {
        throw std::runtime_error("Node with key '" + key + "' does not exist in the graph.");
    }

    size_t degree = 0;
    for (const auto& pair : nodes) {
        const Node& node = pair.second;
        if (node.hasIncomingEdge(key)) {
            degree++;
        }
    }
    return degree;
}

size_t Graph::degree_out(const key_type& key) const {
    if (nodes.count(key) == 0) {
        throw std::runtime_error("Node with key '" + key + "' does not exist in the graph.");
    }

    return nodes.at(key).outgoingEdgesCount();
}

bool Graph::loop(const key_type& key) const {
    if (nodes.count(key) == 0) {
        throw std::runtime_error("Node with key '" + key + "' does not exist in the graph.");
    }

    return nodes.at(key).hasLoop();
}