function blkStruct = slblocks
% This function specifies that the library should appear
% in the Library Browser% and be cached in the browser repository
Browser.Library = 'ece3413';% 'mylib' is the name of the library
Browser.Name = 'ECE3413 Library';% 'My Library' is the library name that appears in the Library Browser
Browser.IsFlat = 1;

blkStruct.Name = ['ECE3413 Library'];
blkStruct.OpenFcn = 'ece3413'; % Name of the .mdl file
blkStruct.MaskDisplay = '';
blkStruct.Browser = Browser;
