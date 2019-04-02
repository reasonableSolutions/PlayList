/*
Title:
    PlayList class implementation file
Name:
    Ka Ming Wong
Date:
    October 17, 2018
Assignment:
    CSCI 235, Fall '18, Project 3
Description:
    Implementation file for PlayList class, which stores Songs in a LinkedSet and
    has methods for manipulating the Songs within
*/

#include <iostream>
#include <string>
#include <vector>

#include "SetInterface.h"
#include "LinkedSet.h"
#include "Node.h"
#include "Song.h"
#include "PlayList.h"

//default constructor
PlayList::PlayList()
{
    LinkedSet<Song>();
    tail_ptr_ = nullptr;
}

//parameterized constructor
PlayList::PlayList(const Song& a_song)
{
    LinkedSet<Song>();
    add(a_song);
    tail_ptr_ = head_ptr_;
}

//copy constructor
PlayList::PlayList(const PlayList& a_playlist) : LinkedSet(a_playlist)
{
    tail_ptr_ = getPointerToLastNode();
}

//destructor
PlayList::~PlayList()
{
    unloop();
}

//helper function for getting pointers to things
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const
{
    bool found = false;
    Node<Song>* cur_ptr = head_ptr_; //variable to store current place in chain
    previous_ptr = nullptr;

    if (contains(target)) //checking to see that it's in the PlayList, otherwise will traverse looped chain forever
    {
        while (!found && (cur_ptr != nullptr)) //while target's not yet found
        {
            if (target == cur_ptr->getItem())
            {
                found = true; //stop if found
            }
            else //continue to traverse through chain, updating parameter and variable
            {
                previous_ptr = cur_ptr;
                cur_ptr = cur_ptr->getNext();
            }
        }
    } // end while
   return cur_ptr; //return results
}

//helper function, traverses chain and returns pointer to last node
Node<Song>* PlayList::getPointerToLastNode() const
{
    Node<Song>* lastNode = nullptr; //variable to store pointer to last node
    Node<Song>* curChain = head_ptr_; //variable for keeping place in chain
    while (curChain != nullptr && curChain != tail_ptr_) //if chain not empty, and we're not at the last node
    {
        curChain = curChain->getNext(); //go to next node
        if (curChain->getNext() == nullptr || curChain == tail_ptr_) //when reach end of unlooped chain or same place as tail_ptr_ in looped chain
        {
            lastNode = curChain;
            return lastNode; //return pointer to last node
        }
    }
    return nullptr; //if chain empty, return null
}

//function for adding Songs to PlayList
bool PlayList::add(const Song& new_song)
{
    //preventing duplicates
    if (!contains(new_song))
    {
        //if the PlayList is not empty, add to end of chain
        if (!isEmpty())
        {
            //instantiate and populate new node
            Node<Song>* next_node_ptr = new Node<Song>();
            next_node_ptr->setItem(new_song);

            //link up old tail with new node
            tail_ptr_->setNext(next_node_ptr);
            //new node is now the tail
            tail_ptr_ = next_node_ptr;
            item_count_++;//update item count as appropriate

            return true;//report success
        }
        //if empty add and set both head and tail ptrs to it
        else
        {
            Node<Song>* next_node_ptr = new Node<Song>();
            next_node_ptr->setItem(new_song);

            tail_ptr_ = next_node_ptr;
            head_ptr_ = next_node_ptr;
            item_count_++;

            return true; //report success
        }
    }
    else
    {
        return false; //PlayList already contains that song, don't add
    }
}

//finds and removes a_song from PlayList, preserving link order
bool PlayList::remove(const Song& a_song)
{
    Node<Song>* found_ptr = nullptr;
    Node<Song>* prev_found_ptr = nullptr;
    found_ptr = getPointerTo(a_song, prev_found_ptr);
    bool first = (prev_found_ptr == nullptr); //flag for found at first node
    bool last = (found_ptr == tail_ptr_); //flag for found at last node
    bool middle = (prev_found_ptr != nullptr && found_ptr != nullptr); //flag for found somewhere in middle
    if (found_ptr != nullptr) //if found
    {
        if (first)
        {
            head_ptr_ = found_ptr->getNext(); //set head to 2nd node
        }
        if (last)
        {
            prev_found_ptr->setNext(nullptr); //set second-to-last node to go nowhere
            tail_ptr_ = prev_found_ptr; //set tail to second-to-last node
        }
        if (middle)
        {
            prev_found_ptr->setNext(found_ptr->getNext());//set node before target to target's next
        }

        //delete target and undangle pointer to target
        delete found_ptr;
        found_ptr = nullptr;
        return true;
    }
    else return false;
}

//prints to console a formatted list of Songs in PlayList with information
void PlayList::displayPlayList()
{
    std::vector<Song> song_vector=toVector(); //get list of songs into vector
    //traverse and print vector as appropriate
    for (int i=0; i < song_vector.size(); i++)
    {
        std::string title = song_vector[i].getTitle();
        std::string author = song_vector[i].getAuthor();
        std::string album = song_vector[i].getAlbum();
        //outputting desired line for each Song
        std::cout << "* Title: " << title << " * Author: " << author << " * Album: "
         << album << " *\n";
    }
    //Regardless of whether there are any Songs in playlist_, output this message at the end
    std::cout << "End of playlist\n";
}

//loops chain in PlayList by pointing last node to first node
void PlayList::loop()
{
    if (!isEmpty())
    {
        if (tail_ptr_->getNext() != head_ptr_) //if not looped
        {
            tail_ptr_->setNext(head_ptr_); //loop
        }
    }
}

//unloops chain in PlayList by pointing last node to nullptr
void PlayList::unloop()
{
    if (!isEmpty())
    {
        if (tail_ptr_->getNext() == head_ptr_) //if looped
        {
            tail_ptr_->setNext(nullptr); //unloop
        }
    }
}
