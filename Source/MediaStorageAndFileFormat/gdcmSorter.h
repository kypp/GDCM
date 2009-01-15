/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006-2009 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef __gdcmSorter_h
#define __gdcmSorter_h

#include "gdcmDirectory.h"
#include "gdcmTag.h"

#include <vector>
#include <string>
#include <map>

namespace gdcm
{
/**
 * \brief Sorter
 */
class DataSet;
class GDCM_EXPORT Sorter
{
public:
  Sorter();
  virtual ~Sorter();

  /// Typically the output of gdcm::Directory::GetFilenames()
  virtual bool Sort(std::vector<std::string> const & filenames);

  /// Return the list of filenames as sorted by the specific algorithm used.
  /// Empty by default (before Sort() is called)
  const std::vector<std::string> &GetFilenames() const { return Filenames; }

  /// Print
  void Print(std::ostream &os) const;

  /// UNSUPPORTED FOR NOW
  bool AddSelect( Tag const &tag, const char *value );

  /// Set the sort function which compares one dataset to the other
  typedef bool (*SortFunction)(DataSet const &, DataSet const &);
  void SetSortFunction( SortFunction f );

  bool StableSort(std::vector<std::string> const & filenames);

protected:
  std::vector<std::string> Filenames;
  typedef std::map<Tag,std::string> SelectionMap;
  std::map<Tag,std::string> Selection;
  SortFunction SortFunc;
};


} // end namespace gdcm

#endif //__gdcmSorter_h
