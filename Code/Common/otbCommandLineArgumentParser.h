/*=========================================================================

  Programme :   OTB (ORFEO ToolBox)
  Auteurs   :   CS - T.Feuvrier
  Language  :   C++
  Date      :   10 f�vrier 2006
  Version   :   
  Role      :   Classe permettant de g�er les param�tres d'une ligne de commande d'un programme
  $Id$

=========================================================================*/
#ifndef __otbCommandLineArgumentParser_h_
#define __otbCommandLineArgumentParser_h_

#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#pragma warning ( disable : 4503 )
#endif

#include <vector>
#include <string>
#include <list>
#include <map>

#include "itkIndent.h"

namespace otb
{

/**
 * \class CommandLineArgumentParseResult
 * \brief Objet retourn� par lCommandLineArgumentParser
 * \see CommandLineArgumentParser
 */
class CommandLineArgumentParseResult
{
public:
  /** Check whether the option was passed in or not */
  bool IsOptionPresent(const char *option);

  /** Get one of the parameters to the option */
  const char *GetOptionParameter(const char *option, unsigned int number = 0);
  
  void PrintSelf(std::ostream& os/*, itk::Indent indent*/) const;

  template< typename TypeValeur >
  TypeValeur GetOptionParameterNumericValue(const char *option, unsigned int number)const;


private:
  typedef std::vector< std::string > ParameterArrayType;
  typedef std::map< std::string, ParameterArrayType> OptionMapType;

  void Clear();
  void AddOption(const std::string &option, int nParms);
  void AddParameter(const std::string &option, const std::string &parameter);

  OptionMapType m_OptionMap;

  friend class CommandLineArgumentParser;
};

/**
 * \class CommandLineArgumentParser
 * \brief Utilis� pour parser une ligne de commande contenant des arguments et la traduit en liste de param�tres.
 * Usage:
 * \code
 *    // Initialise le parser
 *    CommandLineArgumentParser parser;
 *    parser.AddOption("-f",1);
 *    parser.AddSynonim("-f","--filename");
 *    parser.AddOption("-v",0);
 *    parser.AddSynonim("-v","--verbose");
 *
 *    // Utilise le parser
 *    CommandLineArgumentParseResult result;
 *    if(parser.TryParseCommandLine(argc,argv,result)) {
 *       if(result.IsOptionPresent("-f"))
 *          cout << "Filename " << result.GetOptionParameter("-f") << endl;
 *       ...
 *    } 
 * \endcode      
 */
class CommandLineArgumentParser
{
public:
  /** Add an option with 0 or more parameters (words that follow it) */
  void AddOption(const char *name, const int nParameters, const char * comment);
  
  /** Add a different string that envokes the same option (--file and -f) */  
  void AddSynonim(const char *option, const char *synonim);

  /** Try processing a command line.  Returns false if something breaks */
  bool TryParseCommandLine(int argc, char *argv[], 
                           CommandLineArgumentParseResult &outResult,
                           bool failOnUnknownTrailingParameters = true);

  void PrintUsage(std::ostream& os/*, itk::Indent indent*/) const;

private:
  // Synonim list type
  typedef std::list< std::string > NameListType;
  typedef struct 
    {
    std::string CommonName;
    std::string CommentName;
    unsigned int NumberOfParameters;
    } OptionType;
  typedef std::map< std::string, OptionType> OptionMapType;
  
  OptionMapType m_OptionMap;


  std::string m_ProgramName;
};


#ifndef OTB_MANUAL_INSTANTIATION
#include "otbCommandLineArgumentParser.txx"
#endif

}

#endif // __otbCommandLineArgumentParser_h_
