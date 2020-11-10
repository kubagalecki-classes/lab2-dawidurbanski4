#pragma once

#include "Resource.hpp"
#include <iostream>

class ResourceManager
{
public:

  ResourceManager() {
    nowy = new Resource;
  }

  ~ResourceManager()
  {
    //std::cout << "ResourceManager umarl i "<< nowy << "umarl \n";
    delete nowy;
  }

  ResourceManager(const ResourceManager& rs)
  {
        nowy = new Resource{*rs.res};
        //std::cout << "konstruktor kopiujacy zadzialal- "<< nowy << "\n";
  }

  ResourceManager& operator=(const ResourceManager& rs)
  {
        if (!(nowy) == nullptr)) {
            //std::cout << "umarl\n";
            delete nowy;
        }
        nowy = new Resource{*rs.nowy};
        //std::cout << "operator kopiujacy zadzialal- "<< nowy << "\n";
        return *this;
  }

  ResourceManager(ResourceManager&& rs)
  {
        nowy    = rs.nowy;
        //std::cout << "konstruktor przenoszacy zadzialal\n";
        rs.nowy = nullptr;
  }

  ResourceManager& operator=(ResourceManager&& rs)
  {
    if (&rs == this)
    {
      //std::cout << "Przenoszacy blad\n";
      return *this;
    }
    delete nowy;

    //std::cout << "operator przenoszacy\n";
    nowy = rs.nowy;
    rs.nowy = nullptr;
    return *this;
    }



  double get()
  {
    return nowy->get();
  }

private:

    Resource* nowy = nullptr;

};
