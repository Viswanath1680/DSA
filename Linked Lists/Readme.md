**Must use** : while( temp != nullptr && temp->next != nullptr )

For DLLS: Before writing temp->next->prev , first check if temp->next is nullptr. i.e;

    if (temp->next != nullptr) {
        temp->next->prev = temp;
    }

Try to give nice names to pointers such as current, prev , forward , runner.. rather than temp and temp2. 