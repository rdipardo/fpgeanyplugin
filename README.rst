fpgeanyplugin package
=====================

|fpc| |cci-build-status|

:WARNING: This package depends on the LCL's `GTK3 interface`_, which is still
          considered alpha quality

.. _GTK3 interface: https://wiki.lazarus.freepascal.org/Roadmap#General_status_of_LCL_interfaces

Usage
------
fpgeanyplugin provides the following units:

+--------------------+--------------------------------------------------------+
| ``geanyplugin``    | compatible with Geany >= 2.1                           |
+--------------------+--------------------------------------------------------+
| ``geanyplugin247`` | compatible with Geany 2.0 (API version 247)            |
+--------------------+--------------------------------------------------------+
| ``geanyplugin240`` | compatible with Geany >= 1.38, < 2.0 (API version 240) |
+--------------------+--------------------------------------------------------+

Include the package in a shared library project and add the appropriate
unit to the ``uses`` section. A subset of `Geany's plugin API`_ will be
callable from your Object Pascal code.

.. _Geany's plugin API: https://www.geany.org/manual/reference

Since they implement different versions of the same interface, you should not 
include more than one unit in the same file. Use a conditional expression if your
project needs to target multiple API versions, e.g.,

.. code-block:: pascal

    {$macro ON}
    uses
    {$if GEANY_API_VERSION > 247}
      geanyplugin
    {$elseif GEANY_API_VERSION > 240}
      geanyplugin247
    {$else}
      geanyplugin240
    {$endif};


Development
-----------
Clone the source tree and submodules::

    git clone --recursive https://github.com/rdipardo/fpgeanyplugin

Run ``make`` to build the package and a sample plugin.
See `example/README <example/README#building>`_ for instructions on building with ``lazbuild``.

Run ``make geany-deps`` to transpile Geany's headers into Object Pascal.
The transpiler script will first check out the git tag of a Geany release.
Versions 1.38, 2.0 and 2.1 are supported.


Requirements
------------
* lazarus >= 3.0
* fpc >= 3.2
* gtk >= 3.24.24

.. |cci-build-status| image:: https://github.com/rdipardo/fpgeanyplugin/actions/workflows/build.yml/badge.svg?event=push
   :alt: Build
   :target: https://github.com/rdipardo/fpgeanyplugin/actions/workflows/build.yml

.. |fpc| image:: https://img.shields.io/github/license/rdipardo/fpgeanyplugin?style=flat-square&color=lightblue&label=Free%20Pascal&logo=lazarus
   :alt: Built with Free Pascal
