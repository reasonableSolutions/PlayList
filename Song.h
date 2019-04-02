/*
Title:
    Song class header file
Name:
    Ka Ming Wong
Date:
    September 13, 2018
Assignment:
    CSCI 235, Fall '18, Project 3
Description:
    Creates interface for objects of type Song which will represent a song to
    be used in other objects
*/

#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED
#include<string>

class Song
{
private:
    //Data fields
    std::string title_;
    std::string author_;
    std::string album_;
public:
    //Default constructor
    Song();
    //Parameterized constructor with some default values
    Song(const std::string& title, const std::string& author="", const std::string& album="");
    //Mutator methods to change data fields
    void setTitle(const std::string& newTitle);
    void setAuthor(const std::string& newAuthor);
    void setAlbum(const std::string& newAlbum);
    //Accessor methods to get values of data fields
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getAlbum() const;
    //Overloading == operator to enable comparing songs for equivalence
    friend bool operator==(const Song& lhs, const Song& rhs);
};

#endif // SONG_H_INCLUDED
