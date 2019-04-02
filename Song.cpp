/*
Title:
    Song class implementation file
Name:
    Ka Ming Wong
Date:
    September 13, 2018
Assignment:
    CSCI 235, Fall '18, Project 3
Description:
    Implements the methods for objects of type Song which will represent a song
    to be used in other objects
*/

#include "Song.h"
#include <string>

//Default constructor
Song::Song()
{
}
//Parameterized constructor, with initializer list
Song::Song(const std::string& title, const std::string& author,
     const std::string& album): title_(title), author_(author), album_(album)
{
}

//Mutator methods for data fields
void Song::setTitle(const std::string& newTitle)
{
    title_ = newTitle;
}
void Song::setAuthor(const std::string& newAuthor)
{
    author_ = newAuthor;
}
void Song::setAlbum(const std::string& newAlbum)
{
    album_ = newAlbum;
}

//Accessor methods to get values of data fields
std::string Song::getTitle() const
{
    return title_;
}
std::string Song::getAuthor() const
{
    return author_;
}
std::string Song::getAlbum() const
{
    return album_;
}

/** Compares two Song objects for equivalence
@param rhs The Song to be compared to the caller Song
@return True if each Song's data fields match, False if otherwise */
//Overloading == operator to enable comparing songs for equivalence
bool operator==(const Song& lhs, const Song& rhs)
{
    //variables to indicate whether operands have matching data fields
    bool sameTitle = (lhs.getTitle() == rhs.getTitle());
    bool sameAuthor = (lhs.getAuthor()== rhs.getAuthor());
    bool sameAlbum = (lhs.getAlbum() == rhs.getAlbum());
    //return whether all three fields match
    return sameTitle && sameAuthor && sameAlbum;
}
