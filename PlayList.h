/*
Title:
    PlayList class header file
Name:
    Ka Ming Wong
Date:
    October 12, 2018
Assignment:
    CSCI 235, Fall '18, Project 3
Description:
    Header file for PlayList class, which stores Songs in a LinkedSet and
    has methods for manipulating the Songs within
*/

#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED

#include "SetInterface.h"
#include "LinkedSet.h"
#include "Node.h"
#include "Song.h"

class PlayList : public LinkedSet<Song>
{
private:
    Node<Song>* tail_ptr_; //points to last node in linked list
    Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const; //returns pointer for object if found

public:
    PlayList(); //default constructor
    PlayList(const Song& a_song); //parameterized constructor
    PlayList(const PlayList& a_play_list); //copy constructor
    ~PlayList(); //destructor

    Node<Song>* getPointerToLastNode() const; //traverses chain and returns pointer to last node
    bool add(const Song& new_song) override;
    bool remove(const Song& a_song) override;
    void loop();
    void unloop();
    void displayPlayList();

    /*
    */
};

#endif // PLAYLIST_H_INCLUDED
