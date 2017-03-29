// Copyright (C) 2016 by iamslash

#include <iostream>
#include <regex>

int main() {

  {
    if (std::regex_match ("subject", std::regex("(sub)(.*)") ))
      std::cout << "string literal matched\n";

    const char cstr[] = "subject";
    std::string s ("subject");
    std::regex e ("(sub)(.*)");

    if (std::regex_match (s,e))
      std::cout << "string object matched\n";

    if ( std::regex_match ( s.begin(), s.end(), e ) )
      std::cout << "range matched\n";

    std::cmatch cm;    // same as std::match_results<const char*> cm;
    std::regex_match (cstr,cm,e);
    std::cout << "string literal with " << cm.size() << " matches\n";

    std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
    std::regex_match (s,sm,e);
    std::cout << "string object with " << sm.size() << " matches\n";

    std::regex_match ( s.cbegin(), s.cend(), sm, e);
    std::cout << "range with " << sm.size() << " matches\n";

    // using explicit flags:
    std::regex_match ( cstr, cm, e, std::regex_constants::match_default );

    std::cout << "the matches were: ";
    for (unsigned i=0; i<cm.size(); ++i) {
      std::cout << "[" << cm[i] << "] ";
    }

    std::cout << std::endl;    
  }
  std::cout << std::endl;    
  {
    // regex_match
    if (std::regex_match ("this subject has a submarine as a subsequence", std::regex("\\b(sub)([^ ]*)") ))
      std::cout << "string literal matched\n";

    const char cstr[] = "this subject has a submarine as a subsequence";
    std::string s ("this subject has a submarine as a subsequence");
    std::regex e ("\\b(sub)([^ ]*)");

    if (std::regex_match (s, e))
      std::cout << "string object matched\n";

    if (std::regex_match (s.begin(), s.end(), e))
      std::cout << "range matched\n";

    std::cmatch cm;    // same as std::match_results<const char*> cm;
    std::regex_match (cstr, cm, e);
    std::cout << "string literal with " << cm.size() << " matches\n";

    std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
    std::regex_match (s,sm,e);
    std::cout << "string object with " << sm.size() << " matches\n";

    std::regex_match ( s.cbegin(), s.cend(), sm, e);
    std::cout << "range with " << sm.size() << " matches\n";

    // using explicit flags:
    std::regex_match ( cstr, cm, e, std::regex_constants::match_default );

    std::cout << "the matches were: ";
    for (unsigned i=0; i<cm.size(); ++i) {
      std::cout << "[" << cm[i] << "] ";
    }

    std::cout << std::endl;
  }
  std::cout << std::endl;
  {
    // regex_search
    std::string s ("this subject has a submarine as a subsequence");
    std::smatch m;
    std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

    std::cout << "Target sequence: " << s << std::endl;
    std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
    std::cout << "The following matches and submatches were found:" << std::endl;

    while (std::regex_search (s, m, e)) { 
      for (auto x:m) {
        std::cout << x << " ";
      }
      std::cout << std::endl;
      s = m.suffix().str();
    }
  }
  std::cout << std::endl;
  {
    std::string s ("there is a needle in this haystack");
    std::smatch m;
    std::regex e ("needle");

    std::cout << "searching for needle in [" << s << "]\n";
    std::regex_search ( s, m, e );

    if (m.ready()) {
      std::cout << m[0] << " found!\n";
      std::cout << "prefix: [" << m.prefix() << "]\n";
      std::cout << "suffix: [" << m.suffix() << "]\n";
    }
  }
  return 0;
}
