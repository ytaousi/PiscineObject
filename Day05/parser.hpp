#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

typedef enum flags
{
    NODE,
    RAIL,
    NETWORK
} t_flags;

typedef enum events
{
    EVENT,
    EVENT_PROBABILITY,
    EVENT_DURATION,
    EVENT_LOCALTION,
} t_events;

class Parser
{
    private:
        // file1  rails network
        std::vector<std::string> _nodes;
        std::vector<std::string> _events;
        std::vector<std::string> _rails;

        // std::vector<std::pair<int, std::pair<std::string, std::string> >> _network;
        // file2  trains models
        std::string _name;
        float _maximumAccelerationForce;
        float _maximumBreakForce;
        std::string _departureStation; // values needed only
        std::string _arrivalStation; // values needed only
        int _hourOfDeparture;
    public:
        Parser(char *file1, char *file2){
            std::ifstream file(file1);

            if (!file.is_open())
            {
                std::cerr << "Error: file not found" << std::endl;
                return;
            }
            std::string line;
            while (std::getline(file, line))
            {
                if(line.substr(0, 5) == "NODES")
                    _nodes.push_back(line);
                else if(line.substr(0, 4) == "RAIL")
                    _rails.push_back(line);
                else if(line.substr(0, 5) == "EVENT")
                    _events.push_back(line);
                else
                    std::cerr << "Error: Parsing Error" << std::endl;
            }
            file.close();
            std::ifstream file(file2);

            if(!file.is_open())
            {
                std::cerr << "Error: file not found" << std::endl;
                return;
            }
            while (std::getline(file, line))
            {
                std::string token[5];
                int i = 0;
                int j = 0;

                for(i = 0; i < line.size() && j < 5; i++)
                {
                    if(line[i] == ' ')
                        j++;
                    token[j] += line[i];
                }
                if j >= 5
            }
            parserParseNode(_nodes);
            parserParseEvent(_events);
            parserParserail(_rails);
        };
        ~Parser(){};
        void parseNode(std::vector<std::string> listNode) {
            for (size_t i = 0; i < listNode.size(); i++) {
                std::cout << listNodes[i] << std::endl;
            }
        };
        void parseRail(std::vector<std::string> listRail) {
            for (size_t i = 0; i < listRail.size(); i++) {
                std::cout << listRail[i] << std::endl;
            }
        };
        void parseEvent(std::vector<std::string> listEvent) {
            for (size_t i = 0; i < listEvent.size(); i++) {
                std::cout << listEvent[i] << std::endl;
            }
        };
};

#endif