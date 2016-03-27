#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
class LinkedList
{
public:
    typedef T DataType;
    using NodeType = std::shared_ptr<const LinkedList<DataType>>;

private:
    DataType data;
    NodeType next;

public:

    static NodeType CreateList(DataType val)
    {
        return std::make_shared< const LinkedList < T >> (val);
    }

    static NodeType AddHead(DataType val, NodeType tail)
    {
        return std::make_shared<LinkedList < T >> (val, tail);
    }

public:

    bool IsTail() const
    {
        return next.get() == nullptr;
    }

    NodeType Behead() const // Like a dictator
    {
        return next;
    }

    DataType GetData() const
    {
        return data;
    }

    // TODO: Make these private to restrict memory management (ex on stack)

    LinkedList(DataType val, NodeType tail = nullptr) : data(val), next(tail) { }
};

template<typename T>
typename LinkedList<T>::NodeType First(typename LinkedList<T>::NodeType seq)
{
    return seq;
}

template<typename T>
typename LinkedList<T>::NodeType Rest(typename LinkedList<T>::NodeType seq)
{
    if (seq.get() != nullptr)
        return seq->Behead();
    else
        return seq;
}

template<typename T>
typename LinkedList<T>::NodeType Cons(typename LinkedList<T>::NodeType node, typename LinkedList<T>::NodeType seq)
{
    return Cons<T>(node->GetData(), seq);
}

template<typename T>
typename LinkedList<T>::NodeType Cons(typename LinkedList<T>::DataType data, typename LinkedList<T>::NodeType seq)
{
    return LinkedList<T>::AddHead(data, seq);
}

template<class Func, typename T>
typename LinkedList<T>::NodeType Map(Func func, typename LinkedList<T>::NodeType seq)
{
    if (seq.get() != nullptr) {
        return Cons<T>(func(First<T>(seq)->GetData()), Map<Func, T>(func, Rest<T>(seq)));
    } else {
        return seq;
    }
}

template<typename T>
typename LinkedList<T>::NodeType Search(typename LinkedList<T>::DataType token, typename LinkedList<T>::NodeType seq)
{
    if (seq->GetData() == token) {
        return seq;
    } else if (seq->IsTail()) {
        return nullptr;
    } else {
        return Search<T>(token, Rest<T>(seq));
    }
}

template<typename T>
typename LinkedList<T>::NodeType Search(typename LinkedList<T>::NodeType token, typename LinkedList<T>::NodeType seq)
{
    if (seq == token) {
        return seq;
    } else if (seq->IsTail()) {
        return nullptr;
    } else {
        return Search<T>(token, Rest<T>(seq));
    }
}

template<typename T>
typename LinkedList<T>::NodeType InsertAfter(typename LinkedList<T>::DataType data, typename LinkedList<T>::NodeType token, typename LinkedList<T>::NodeType seq)
{
    if (seq->IsTail()) {
        return nullptr;
    }

    typename LinkedList<T>::NodeType result = nullptr;

    if (seq == token) {
        result = Cons<T>(data, Rest<T>(seq));
    } else {
        result = InsertAfter<T>(data, token, Rest<T>(seq));
    }
    
    if (result)
        return Cons<T>(seq, result);
    else
        return result;
}

template<typename T>
typename LinkedList<T>::NodeType InsertBefore(typename LinkedList<T>::DataType data, typename LinkedList<T>::NodeType token, typename LinkedList<T>::NodeType seq) { }
#endif /* LINKEDLIST_H */
