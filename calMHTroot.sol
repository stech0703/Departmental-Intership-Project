// SPDX-License-Identifier: MIT
pragma solidity ^0.8.3;
contract MHT
{
    // uint[] public hash=[1,2,3,4,5,6,7,8];
    uint[] public hash;
    uint public mhtroot;
    uint public n;
    uint public proof;
    bool public checkIntegrity;

    // function to take input of the hashtags in array...
    
    function TakeInputHash(uint x) public
    {
        hash.push(x);
    }

    // function to get the size of the array containing hashtags...
    function HashSize() public  
    {  
        n = hash.length;        
    } 
    
    // function to calculate the MHT root...
    
    function MHTroot() public
    {
        uint x = 3; // x = log2(size of hash array)
        uint size = 8; //  size = size of hash array 
        for(uint i=0;i<x;i++)
        {
            uint j=0;
            size=size/2;
            while(j<size)
            {
//              hash[j]=hash[2*j]+hash[2*j+1];
                hash[j]=hash[2*j]+hash[2*j+1];  
                j++;
            }
        }
    }
    function root() public
    {
        mhtroot=hash[0];
    }

    function InputProof(uint input) public
    {
        proof=input;
    }
    
    function verifyProof() public
    {
        if(proof == mhtroot)    
            checkIntegrity=true;
    }

}