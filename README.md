# ExperimentClass

These classes manage standard true and false test results, unknowns, and conflicting information. The evidence class provides a container for results from a single run, storing true, false, untested, and conflicting results. The experiment class allows manipulation of the data from several runs, grouping evidence objects together for statistical analysis.

This design permits a consistent manner of evaluating and reporting response to 'fuzzy' data. It's useful for any situation where tests may not give decisive information, such as where you want to avoid categorizing results in a central threshold as either true or false. For example, in a DAC (digital-to-analog converter) application, if values from 0.4-0.6 of the 'on' value mixed on and off states, those could be categorized as conflicting, allowing for more decisive resolution of results. Feel free to use and adapt this code for your own applications.
