<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<!-- saved from url=(0053)http://docs.python.org/2/library/multiprocessing.html -->
<html xmlns="http://www.w3.org/1999/xhtml"><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    
    
    <title>16.6. multiprocessing — Process-based “threading” interface — Python v2.7.5 documentation</title>
    <link rel="stylesheet" href="./16.6. multiprocessing — Process-based “threading” interface — Python v2.7.5 documentation_files/default.css" type="text/css">
    <link rel="stylesheet" href="./16.6. multiprocessing — Process-based “threading” interface — Python v2.7.5 documentation_files/pygments.css" type="text/css">
    <script type="text/javascript">
      var DOCUMENTATION_OPTIONS = {
        URL_ROOT:    '../',
        VERSION:     '2.7.5',
        COLLAPSE_INDEX: false,
        FILE_SUFFIX: '.html',
        HAS_SOURCE:  true
      };
    </script>
    <script type="text/javascript" src="./16.6. multiprocessing — Process-based “threading” interface — Python v2.7.5 documentation_files/jquery.js"></script>
    <script type="text/javascript" src="./16.6. multiprocessing — Process-based “threading” interface — Python v2.7.5 documentation_files/underscore.js"></script>
    <script type="text/javascript" src="./16.6. multiprocessing — Process-based “threading” interface — Python v2.7.5 documentation_files/doctools.js"></script>
    <script type="text/javascript" src="./16.6. multiprocessing — Process-based “threading” interface — Python v2.7.5 documentation_files/sidebar.js"></script>
    <link rel="search" type="application/opensearchdescription+xml" title="Search within Python v2.7.5 documentation" href="http://docs.python.org/2/_static/opensearch.xml">
    <link rel="author" title="About these documents" href="http://docs.python.org/2/about.html">
    <link rel="copyright" title="Copyright" href="http://docs.python.org/2/copyright.html">
    <link rel="top" title="Python v2.7.5 documentation" href="http://docs.python.org/2/index.html">
    <link rel="up" title="16. Optional Operating System Services" href="http://docs.python.org/2/library/someos.html">
    <link rel="next" title="16.7. mmap — Memory-mapped file support" href="http://docs.python.org/2/library/mmap.html">
    <link rel="prev" title="16.5. dummy_thread — Drop-in replacement for the thread module" href="http://docs.python.org/2/library/dummy_thread.html">
    <link rel="shortcut icon" type="image/png" href="./16.6. multiprocessing — Process-based “threading” interface — Python v2.7.5 documentation_files/py.png">
    <script type="text/javascript" src="./16.6. multiprocessing — Process-based “threading” interface — Python v2.7.5 documentation_files/copybutton.js"></script>
    <script type="text/javascript" src="./16.6. multiprocessing — Process-based “threading” interface — Python v2.7.5 documentation_files/version_switch.js"></script>
 

  </head>
  <body>
    <div class="related">
      <h3>Navigation</h3>
      <ul>
        <li class="right" style="margin-right: 10px">
          <a href="http://docs.python.org/2/genindex.html" title="General Index" accesskey="I">index</a></li>
        <li class="right">
          <a href="http://docs.python.org/2/py-modindex.html" title="Python Module Index">modules</a> |</li>
        <li class="right">
          <a href="http://docs.python.org/2/library/mmap.html" title="16.7. mmap — Memory-mapped file support" accesskey="N">next</a> |</li>
        <li class="right">
          <a href="http://docs.python.org/2/library/dummy_thread.html" title="16.5. dummy_thread — Drop-in replacement for the thread module" accesskey="P">previous</a> |</li>
        <li><img src="./16.6. multiprocessing — Process-based “threading” interface — Python v2.7.5 documentation_files/py.png" alt="" style="vertical-align: middle; margin-top: -1px"></li>
        <li><a href="http://www.python.org/">Python</a> »</li>
        <li>
          <span class="version_switcher_placeholder"><select><option value="3.4">dev (3.4)</option><option value="3.3">3.3</option><option value="3.2">3.2</option><option value="2.7" selected="selected">2.7.5</option><option value="2.6">2.6</option></select></span>
          <a href="http://docs.python.org/2/index.html">Documentation</a> »
        </li>

          <li><a href="http://docs.python.org/2/library/index.html">The Python Standard Library</a> »</li>
          <li><a href="http://docs.python.org/2/library/someos.html" accesskey="U">16. Optional Operating System Services</a> »</li> 
      </ul>
    </div>  

    <div class="document">
      <div class="documentwrapper">
        <div class="bodywrapper">
          <div class="body">
            
  <div class="section" id="module-multiprocessing">
<span id="multiprocessing-process-based-threading-interface"></span><h1>16.6. <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> — Process-based “threading” interface<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="Permalink to this headline">¶</a></h1>
<p class="versionadded">
<span class="versionmodified">New in version 2.6.</span></p>
<div class="section" id="introduction">
<h2>16.6.1. Introduction<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#introduction" title="Permalink to this headline">¶</a></h2>
<p><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> is a package that supports spawning processes using an
API similar to the <a class="reference internal" href="http://docs.python.org/2/library/threading.html#module-threading" title="threading: Higher-level threading interface."><tt class="xref py py-mod docutils literal"><span class="pre">threading</span></tt></a> module.  The <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> package
offers both local and remote concurrency, effectively side-stepping the
<a class="reference internal" href="http://docs.python.org/2/glossary.html#term-global-interpreter-lock"><em class="xref std std-term">Global Interpreter Lock</em></a> by using subprocesses instead of threads.  Due
to this, the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> module allows the programmer to fully
leverage multiple processors on a given machine.  It runs on both Unix and
Windows.</p>
<div class="admonition warning">
<p class="first admonition-title">Warning</p>
<p class="last">Some of this package’s functionality requires a functioning shared semaphore
implementation on the host operating system. Without one, the
<tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing.synchronize</span></tt> module will be disabled, and attempts to
import it will result in an <a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.ImportError" title="exceptions.ImportError"><tt class="xref py py-exc docutils literal"><span class="pre">ImportError</span></tt></a>. See
<a class="reference external" href="http://bugs.python.org/issue3770">issue 3770</a> for additional information.</p>
</div>
<div class="admonition note">
<p class="first admonition-title">Note</p>
<p>Functionality within this package requires that the <tt class="docutils literal"><span class="pre">__main__</span></tt> module be
importable by the children. This is covered in <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-programming"><em>Programming guidelines</em></a>
however it is worth pointing out here. This means that some examples, such
as the <tt class="xref py py-class docutils literal"><span class="pre">multiprocessing.Pool</span></tt> examples will not work in the
interactive interpreter. For example:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Pool</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">p</span> <span class="o">=</span> <span class="n">Pool</span><span class="p">(</span><span class="mi">5</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="n">x</span><span class="p">):</span>
<span class="gp">... </span>    <span class="k">return</span> <span class="n">x</span><span class="o">*</span><span class="n">x</span>
<span class="gp">...</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">p</span><span class="o">.</span><span class="n">map</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="p">[</span><span class="mi">1</span><span class="p">,</span><span class="mi">2</span><span class="p">,</span><span class="mi">3</span><span class="p">])</span>
<span class="go">Process PoolWorker-1:</span>
<span class="go">Process PoolWorker-2:</span>
<span class="go">Process PoolWorker-3:</span>
<span class="gt">Traceback (most recent call last):</span>
<span class="nc">AttributeError</span><span>: </span><span class="n-Identifier">'module' object has no attribute 'f'</span>
<span class="go">AttributeError: 'module' object has no attribute 'f'</span>
<span class="go">AttributeError: 'module' object has no attribute 'f'</span>
</pre></div>
</div>
<p class="last">(If you try this it will actually output three full tracebacks
interleaved in a semi-random fashion, and then you may have to
stop the master process somehow.)</p>
</div>
<div class="section" id="the-process-class">
<h3>16.6.1.1. The <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process" title="multiprocessing.Process"><tt class="xref py py-class docutils literal"><span class="pre">Process</span></tt></a> class<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#the-process-class" title="Permalink to this headline">¶</a></h3>
<p>In <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a>, processes are spawned by creating a <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process" title="multiprocessing.Process"><tt class="xref py py-class docutils literal"><span class="pre">Process</span></tt></a>
object and then calling its <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.start" title="multiprocessing.Process.start"><tt class="xref py py-meth docutils literal"><span class="pre">start()</span></tt></a> method.  <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process" title="multiprocessing.Process"><tt class="xref py py-class docutils literal"><span class="pre">Process</span></tt></a>
follows the API of <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Thread" title="threading.Thread"><tt class="xref py py-class docutils literal"><span class="pre">threading.Thread</span></tt></a>.  A trivial example of a
multiprocess program is</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="n">name</span><span class="p">):</span>
    <span class="k">print</span> <span class="s">'hello'</span><span class="p">,</span> <span class="n">name</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">p</span> <span class="o">=</span> <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">f</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="s">'bob'</span><span class="p">,))</span>
    <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
    <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>
</pre></div>
</div>
<p>To show the individual process IDs involved, here is an expanded example:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span>
<span class="kn">import</span> <span class="nn">os</span>

<span class="k">def</span> <span class="nf">info</span><span class="p">(</span><span class="n">title</span><span class="p">):</span>
    <span class="k">print</span> <span class="n">title</span>
    <span class="k">print</span> <span class="s">'module name:'</span><span class="p">,</span> <span class="n">__name__</span>
    <span class="k">if</span> <span class="nb">hasattr</span><span class="p">(</span><span class="n">os</span><span class="p">,</span> <span class="s">'getppid'</span><span class="p">):</span>  <span class="c"># only available on Unix</span>
        <span class="k">print</span> <span class="s">'parent process:'</span><span class="p">,</span> <span class="n">os</span><span class="o">.</span><span class="n">getppid</span><span class="p">()</span>
    <span class="k">print</span> <span class="s">'process id:'</span><span class="p">,</span> <span class="n">os</span><span class="o">.</span><span class="n">getpid</span><span class="p">()</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="n">name</span><span class="p">):</span>
    <span class="n">info</span><span class="p">(</span><span class="s">'function f'</span><span class="p">)</span>
    <span class="k">print</span> <span class="s">'hello'</span><span class="p">,</span> <span class="n">name</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">info</span><span class="p">(</span><span class="s">'main line'</span><span class="p">)</span>
    <span class="n">p</span> <span class="o">=</span> <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">f</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="s">'bob'</span><span class="p">,))</span>
    <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
    <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>
</pre></div>
</div>
<p>For an explanation of why (on Windows) the <tt class="docutils literal"><span class="pre">if</span> <span class="pre">__name__</span> <span class="pre">==</span> <span class="pre">'__main__'</span></tt> part is
necessary, see <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-programming"><em>Programming guidelines</em></a>.</p>
</div>
<div class="section" id="exchanging-objects-between-processes">
<h3>16.6.1.2. Exchanging objects between processes<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#exchanging-objects-between-processes" title="Permalink to this headline">¶</a></h3>
<p><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> supports two types of communication channel between
processes:</p>
<p><strong>Queues</strong></p>
<blockquote>
<div><p>The <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue" title="multiprocessing.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue</span></tt></a> class is a near clone of <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Queue" title="Queue.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue.Queue</span></tt></a>.  For
example:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">Queue</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="n">q</span><span class="p">):</span>
    <span class="n">q</span><span class="o">.</span><span class="n">put</span><span class="p">([</span><span class="mi">42</span><span class="p">,</span> <span class="bp">None</span><span class="p">,</span> <span class="s">'hello'</span><span class="p">])</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">q</span> <span class="o">=</span> <span class="n">Queue</span><span class="p">()</span>
    <span class="n">p</span> <span class="o">=</span> <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">f</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">q</span><span class="p">,))</span>
    <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
    <span class="k">print</span> <span class="n">q</span><span class="o">.</span><span class="n">get</span><span class="p">()</span>    <span class="c"># prints "[42, None, 'hello']"</span>
    <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>
</pre></div>
</div>
<p>Queues are thread and process safe.</p>
</div></blockquote>
<p><strong>Pipes</strong></p>
<blockquote>
<div><p>The <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Pipe" title="multiprocessing.Pipe"><tt class="xref py py-func docutils literal"><span class="pre">Pipe()</span></tt></a> function returns a pair of connection objects connected by a
pipe which by default is duplex (two-way).  For example:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">Pipe</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="n">conn</span><span class="p">):</span>
    <span class="n">conn</span><span class="o">.</span><span class="n">send</span><span class="p">([</span><span class="mi">42</span><span class="p">,</span> <span class="bp">None</span><span class="p">,</span> <span class="s">'hello'</span><span class="p">])</span>
    <span class="n">conn</span><span class="o">.</span><span class="n">close</span><span class="p">()</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">parent_conn</span><span class="p">,</span> <span class="n">child_conn</span> <span class="o">=</span> <span class="n">Pipe</span><span class="p">()</span>
    <span class="n">p</span> <span class="o">=</span> <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">f</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">child_conn</span><span class="p">,))</span>
    <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
    <span class="k">print</span> <span class="n">parent_conn</span><span class="o">.</span><span class="n">recv</span><span class="p">()</span>   <span class="c"># prints "[42, None, 'hello']"</span>
    <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>
</pre></div>
</div>
<p>The two connection objects returned by <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Pipe" title="multiprocessing.Pipe"><tt class="xref py py-func docutils literal"><span class="pre">Pipe()</span></tt></a> represent the two ends of
the pipe.  Each connection object has <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.send" title="multiprocessing.Connection.send"><tt class="xref py py-meth docutils literal"><span class="pre">send()</span></tt></a> and
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.recv" title="multiprocessing.Connection.recv"><tt class="xref py py-meth docutils literal"><span class="pre">recv()</span></tt></a> methods (among others).  Note that data in a pipe
may become corrupted if two processes (or threads) try to read from or write
to the <em>same</em> end of the pipe at the same time.  Of course there is no risk
of corruption from processes using different ends of the pipe at the same
time.</p>
</div></blockquote>
</div>
<div class="section" id="synchronization-between-processes">
<h3>16.6.1.3. Synchronization between processes<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#synchronization-between-processes" title="Permalink to this headline">¶</a></h3>
<p><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> contains equivalents of all the synchronization
primitives from <a class="reference internal" href="http://docs.python.org/2/library/threading.html#module-threading" title="threading: Higher-level threading interface."><tt class="xref py py-mod docutils literal"><span class="pre">threading</span></tt></a>.  For instance one can use a lock to ensure
that only one process prints to standard output at a time:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">Lock</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="n">l</span><span class="p">,</span> <span class="n">i</span><span class="p">):</span>
    <span class="n">l</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
    <span class="k">print</span> <span class="s">'hello world'</span><span class="p">,</span> <span class="n">i</span>
    <span class="n">l</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">lock</span> <span class="o">=</span> <span class="n">Lock</span><span class="p">()</span>

    <span class="k">for</span> <span class="n">num</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">):</span>
        <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">f</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">lock</span><span class="p">,</span> <span class="n">num</span><span class="p">))</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
</pre></div>
</div>
<p>Without using the lock output from the different processes is liable to get all
mixed up.</p>
</div>
<div class="section" id="sharing-state-between-processes">
<h3>16.6.1.4. Sharing state between processes<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#sharing-state-between-processes" title="Permalink to this headline">¶</a></h3>
<p>As mentioned above, when doing concurrent programming it is usually best to
avoid using shared state as far as possible.  This is particularly true when
using multiple processes.</p>
<p>However, if you really do need to use some shared data then
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> provides a couple of ways of doing so.</p>
<p><strong>Shared memory</strong></p>
<blockquote>
<div><p>Data can be stored in a shared memory map using <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Value" title="multiprocessing.Value"><tt class="xref py py-class docutils literal"><span class="pre">Value</span></tt></a> or
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Array" title="multiprocessing.Array"><tt class="xref py py-class docutils literal"><span class="pre">Array</span></tt></a>.  For example, the following code</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">Value</span><span class="p">,</span> <span class="n">Array</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="n">n</span><span class="p">,</span> <span class="n">a</span><span class="p">):</span>
    <span class="n">n</span><span class="o">.</span><span class="n">value</span> <span class="o">=</span> <span class="mf">3.1415927</span>
    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="nb">len</span><span class="p">(</span><span class="n">a</span><span class="p">)):</span>
        <span class="n">a</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="o">-</span><span class="n">a</span><span class="p">[</span><span class="n">i</span><span class="p">]</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">num</span> <span class="o">=</span> <span class="n">Value</span><span class="p">(</span><span class="s">'d'</span><span class="p">,</span> <span class="mf">0.0</span><span class="p">)</span>
    <span class="n">arr</span> <span class="o">=</span> <span class="n">Array</span><span class="p">(</span><span class="s">'i'</span><span class="p">,</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">))</span>

    <span class="n">p</span> <span class="o">=</span> <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">f</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">num</span><span class="p">,</span> <span class="n">arr</span><span class="p">))</span>
    <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
    <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>

    <span class="k">print</span> <span class="n">num</span><span class="o">.</span><span class="n">value</span>
    <span class="k">print</span> <span class="n">arr</span><span class="p">[:]</span>
</pre></div>
</div>
<p>will print</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="mf">3.1415927</span>
<span class="p">[</span><span class="mi">0</span><span class="p">,</span> <span class="o">-</span><span class="mi">1</span><span class="p">,</span> <span class="o">-</span><span class="mi">2</span><span class="p">,</span> <span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="o">-</span><span class="mi">4</span><span class="p">,</span> <span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="o">-</span><span class="mi">6</span><span class="p">,</span> <span class="o">-</span><span class="mi">7</span><span class="p">,</span> <span class="o">-</span><span class="mi">8</span><span class="p">,</span> <span class="o">-</span><span class="mi">9</span><span class="p">]</span>
</pre></div>
</div>
<p>The <tt class="docutils literal"><span class="pre">'d'</span></tt> and <tt class="docutils literal"><span class="pre">'i'</span></tt> arguments used when creating <tt class="docutils literal"><span class="pre">num</span></tt> and <tt class="docutils literal"><span class="pre">arr</span></tt> are
typecodes of the kind used by the <a class="reference internal" href="http://docs.python.org/2/library/array.html#module-array" title="array: Space efficient arrays of uniformly typed numeric values."><tt class="xref py py-mod docutils literal"><span class="pre">array</span></tt></a> module: <tt class="docutils literal"><span class="pre">'d'</span></tt> indicates a
double precision float and <tt class="docutils literal"><span class="pre">'i'</span></tt> indicates a signed integer.  These shared
objects will be process and thread-safe.</p>
<p>For more flexibility in using shared memory one can use the
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.sharedctypes" title="multiprocessing.sharedctypes: Allocate ctypes objects from shared memory."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing.sharedctypes</span></tt></a> module which supports the creation of
arbitrary ctypes objects allocated from shared memory.</p>
</div></blockquote>
<p><strong>Server process</strong></p>
<blockquote>
<div><p>A manager object returned by <tt class="xref py py-func docutils literal"><span class="pre">Manager()</span></tt> controls a server process which
holds Python objects and allows other processes to manipulate them using
proxies.</p>
<p>A manager returned by <tt class="xref py py-func docutils literal"><span class="pre">Manager()</span></tt> will support types <a class="reference internal" href="http://docs.python.org/2/library/functions.html#list" title="list"><tt class="xref py py-class docutils literal"><span class="pre">list</span></tt></a>,
<a class="reference internal" href="http://docs.python.org/2/library/stdtypes.html#dict" title="dict"><tt class="xref py py-class docutils literal"><span class="pre">dict</span></tt></a>, <tt class="xref py py-class docutils literal"><span class="pre">Namespace</span></tt>, <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Lock" title="multiprocessing.Lock"><tt class="xref py py-class docutils literal"><span class="pre">Lock</span></tt></a>, <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.RLock" title="multiprocessing.RLock"><tt class="xref py py-class docutils literal"><span class="pre">RLock</span></tt></a>,
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Semaphore" title="multiprocessing.Semaphore"><tt class="xref py py-class docutils literal"><span class="pre">Semaphore</span></tt></a>, <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.BoundedSemaphore" title="multiprocessing.BoundedSemaphore"><tt class="xref py py-class docutils literal"><span class="pre">BoundedSemaphore</span></tt></a>, <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Condition" title="multiprocessing.Condition"><tt class="xref py py-class docutils literal"><span class="pre">Condition</span></tt></a>,
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Event" title="multiprocessing.Event"><tt class="xref py py-class docutils literal"><span class="pre">Event</span></tt></a>, <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue" title="multiprocessing.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue</span></tt></a>, <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Value" title="multiprocessing.Value"><tt class="xref py py-class docutils literal"><span class="pre">Value</span></tt></a> and <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Array" title="multiprocessing.Array"><tt class="xref py py-class docutils literal"><span class="pre">Array</span></tt></a>.  For
example,</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">Manager</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="n">d</span><span class="p">,</span> <span class="n">l</span><span class="p">):</span>
    <span class="n">d</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">=</span> <span class="s">'1'</span>
    <span class="n">d</span><span class="p">[</span><span class="s">'2'</span><span class="p">]</span> <span class="o">=</span> <span class="mi">2</span>
    <span class="n">d</span><span class="p">[</span><span class="mf">0.25</span><span class="p">]</span> <span class="o">=</span> <span class="bp">None</span>
    <span class="n">l</span><span class="o">.</span><span class="n">reverse</span><span class="p">()</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">manager</span> <span class="o">=</span> <span class="n">Manager</span><span class="p">()</span>

    <span class="n">d</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">dict</span><span class="p">()</span>
    <span class="n">l</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">list</span><span class="p">(</span><span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">))</span>

    <span class="n">p</span> <span class="o">=</span> <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">f</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">d</span><span class="p">,</span> <span class="n">l</span><span class="p">))</span>
    <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
    <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>

    <span class="k">print</span> <span class="n">d</span>
    <span class="k">print</span> <span class="n">l</span>
</pre></div>
</div>
<p>will print</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="p">{</span><span class="mf">0.25</span><span class="p">:</span> <span class="bp">None</span><span class="p">,</span> <span class="mi">1</span><span class="p">:</span> <span class="s">'1'</span><span class="p">,</span> <span class="s">'2'</span><span class="p">:</span> <span class="mi">2</span><span class="p">}</span>
<span class="p">[</span><span class="mi">9</span><span class="p">,</span> <span class="mi">8</span><span class="p">,</span> <span class="mi">7</span><span class="p">,</span> <span class="mi">6</span><span class="p">,</span> <span class="mi">5</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="mi">2</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">0</span><span class="p">]</span>
</pre></div>
</div>
<p>Server process managers are more flexible than using shared memory objects
because they can be made to support arbitrary object types.  Also, a single
manager can be shared by processes on different computers over a network.
They are, however, slower than using shared memory.</p>
</div></blockquote>
</div>
<div class="section" id="using-a-pool-of-workers">
<h3>16.6.1.5. Using a pool of workers<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#using-a-pool-of-workers" title="Permalink to this headline">¶</a></h3>
<p>The <tt class="xref py py-class docutils literal"><span class="pre">Pool</span></tt> class represents a pool of worker
processes.  It has methods which allows tasks to be offloaded to the worker
processes in a few different ways.</p>
<p>For example:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Pool</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="n">x</span><span class="p">):</span>
    <span class="k">return</span> <span class="n">x</span><span class="o">*</span><span class="n">x</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">pool</span> <span class="o">=</span> <span class="n">Pool</span><span class="p">(</span><span class="n">processes</span><span class="o">=</span><span class="mi">4</span><span class="p">)</span>              <span class="c"># start 4 worker processes</span>
    <span class="n">result</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">apply_async</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="p">[</span><span class="mi">10</span><span class="p">])</span>    <span class="c"># evaluate "f(10)" asynchronously</span>
    <span class="k">print</span> <span class="n">result</span><span class="o">.</span><span class="n">get</span><span class="p">(</span><span class="n">timeout</span><span class="o">=</span><span class="mi">1</span><span class="p">)</span>           <span class="c"># prints "100" unless your computer is *very* slow</span>
    <span class="k">print</span> <span class="n">pool</span><span class="o">.</span><span class="n">map</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">))</span>          <span class="c"># prints "[0, 1, 4,..., 81]"</span>
</pre></div>
</div>
<p>Note that the methods of a pool should only ever be used by the
process which created it.</p>
</div>
</div>
<div class="section" id="reference">
<h2>16.6.2. Reference<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#reference" title="Permalink to this headline">¶</a></h2>
<p>The <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> package mostly replicates the API of the
<a class="reference internal" href="http://docs.python.org/2/library/threading.html#module-threading" title="threading: Higher-level threading interface."><tt class="xref py py-mod docutils literal"><span class="pre">threading</span></tt></a> module.</p>
<div class="section" id="process-and-exceptions">
<h3>16.6.2.1. <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process" title="multiprocessing.Process"><tt class="xref py py-class docutils literal"><span class="pre">Process</span></tt></a> and exceptions<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#process-and-exceptions" title="Permalink to this headline">¶</a></h3>
<dl class="class">
<dt id="multiprocessing.Process">
<em class="property">class </em><tt class="descclassname">multiprocessing.</tt><tt class="descname">Process</tt><big>(</big><em>group=None</em>, <em>target=None</em>, <em>name=None</em>, <em>args=()</em>, <em>kwargs={}</em><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process" title="Permalink to this definition">¶</a></dt>
<dd><p>Process objects represent activity that is run in a separate process. The
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process" title="multiprocessing.Process"><tt class="xref py py-class docutils literal"><span class="pre">Process</span></tt></a> class has equivalents of all the methods of
<a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Thread" title="threading.Thread"><tt class="xref py py-class docutils literal"><span class="pre">threading.Thread</span></tt></a>.</p>
<p>The constructor should always be called with keyword arguments. <em>group</em>
should always be <tt class="xref docutils literal"><span class="pre">None</span></tt>; it exists solely for compatibility with
<a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Thread" title="threading.Thread"><tt class="xref py py-class docutils literal"><span class="pre">threading.Thread</span></tt></a>.  <em>target</em> is the callable object to be invoked by
the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.run" title="multiprocessing.Process.run"><tt class="xref py py-meth docutils literal"><span class="pre">run()</span></tt></a> method.  It defaults to <tt class="xref docutils literal"><span class="pre">None</span></tt>, meaning nothing is
called. <em>name</em> is the process name.  By default, a unique name is constructed
of the form ‘Process-N<sub>1</sub>:N<sub>2</sub>:...:N<sub>k</sub>‘ where N<sub>1</sub>,N<sub>2</sub>,...,N<sub>k</sub> is a sequence of integers whose length
is determined by the <em>generation</em> of the process.  <em>args</em> is the argument
tuple for the target invocation.  <em>kwargs</em> is a dictionary of keyword
arguments for the target invocation.  By default, no arguments are passed to
<em>target</em>.</p>
<p>If a subclass overrides the constructor, it must make sure it invokes the
base class constructor (<tt class="xref py py-meth docutils literal"><span class="pre">Process.__init__()</span></tt>) before doing anything else
to the process.</p>
<dl class="method">
<dt id="multiprocessing.Process.run">
<tt class="descname">run</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.run" title="Permalink to this definition">¶</a></dt>
<dd><p>Method representing the process’s activity.</p>
<p>You may override this method in a subclass.  The standard <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.run" title="multiprocessing.Process.run"><tt class="xref py py-meth docutils literal"><span class="pre">run()</span></tt></a>
method invokes the callable object passed to the object’s constructor as
the target argument, if any, with sequential and keyword arguments taken
from the <em>args</em> and <em>kwargs</em> arguments, respectively.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Process.start">
<tt class="descname">start</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.start" title="Permalink to this definition">¶</a></dt>
<dd><p>Start the process’s activity.</p>
<p>This must be called at most once per process object.  It arranges for the
object’s <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.run" title="multiprocessing.Process.run"><tt class="xref py py-meth docutils literal"><span class="pre">run()</span></tt></a> method to be invoked in a separate process.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Process.join">
<tt class="descname">join</tt><big>(</big><span class="optional">[</span><em>timeout</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.join" title="Permalink to this definition">¶</a></dt>
<dd><p>Block the calling thread until the process whose <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.join" title="multiprocessing.Process.join"><tt class="xref py py-meth docutils literal"><span class="pre">join()</span></tt></a> method is
called terminates or until the optional timeout occurs.</p>
<p>If <em>timeout</em> is <tt class="xref docutils literal"><span class="pre">None</span></tt> then there is no timeout.</p>
<p>A process can be joined many times.</p>
<p>A process cannot join itself because this would cause a deadlock.  It is
an error to attempt to join a process before it has been started.</p>
</dd></dl>

<dl class="attribute">
<dt id="multiprocessing.Process.name">
<tt class="descname">name</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.name" title="Permalink to this definition">¶</a></dt>
<dd><p>The process’s name.</p>
<p>The name is a string used for identification purposes only.  It has no
semantics.  Multiple processes may be given the same name.  The initial
name is set by the constructor.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Process.is_alive">
<tt class="descname">is_alive</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.is_alive" title="Permalink to this definition">¶</a></dt>
<dd><p>Return whether the process is alive.</p>
<p>Roughly, a process object is alive from the moment the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.start" title="multiprocessing.Process.start"><tt class="xref py py-meth docutils literal"><span class="pre">start()</span></tt></a>
method returns until the child process terminates.</p>
</dd></dl>

<dl class="attribute">
<dt id="multiprocessing.Process.daemon">
<tt class="descname">daemon</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.daemon" title="Permalink to this definition">¶</a></dt>
<dd><p>The process’s daemon flag, a Boolean value.  This must be set before
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.start" title="multiprocessing.Process.start"><tt class="xref py py-meth docutils literal"><span class="pre">start()</span></tt></a> is called.</p>
<p>The initial value is inherited from the creating process.</p>
<p>When a process exits, it attempts to terminate all of its daemonic child
processes.</p>
<p>Note that a daemonic process is not allowed to create child processes.
Otherwise a daemonic process would leave its children orphaned if it gets
terminated when its parent process exits. Additionally, these are <strong>not</strong>
Unix daemons or services, they are normal processes that will be
terminated (and not joined) if non-daemonic processes have exited.</p>
</dd></dl>

<p>In addition to the  <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Thread" title="threading.Thread"><tt class="xref py py-class docutils literal"><span class="pre">threading.Thread</span></tt></a> API, <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process" title="multiprocessing.Process"><tt class="xref py py-class docutils literal"><span class="pre">Process</span></tt></a> objects
also support the following attributes and methods:</p>
<dl class="attribute">
<dt id="multiprocessing.Process.pid">
<tt class="descname">pid</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.pid" title="Permalink to this definition">¶</a></dt>
<dd><p>Return the process ID.  Before the process is spawned, this will be
<tt class="xref docutils literal"><span class="pre">None</span></tt>.</p>
</dd></dl>

<dl class="attribute">
<dt id="multiprocessing.Process.exitcode">
<tt class="descname">exitcode</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.exitcode" title="Permalink to this definition">¶</a></dt>
<dd><p>The child’s exit code.  This will be <tt class="xref docutils literal"><span class="pre">None</span></tt> if the process has not yet
terminated.  A negative value <em>-N</em> indicates that the child was terminated
by signal <em>N</em>.</p>
</dd></dl>

<dl class="attribute">
<dt id="multiprocessing.Process.authkey">
<tt class="descname">authkey</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.authkey" title="Permalink to this definition">¶</a></dt>
<dd><p>The process’s authentication key (a byte string).</p>
<p>When <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> is initialized the main process is assigned a
random string using <a class="reference internal" href="http://docs.python.org/2/library/os.html#os.urandom" title="os.urandom"><tt class="xref py py-func docutils literal"><span class="pre">os.urandom()</span></tt></a>.</p>
<p>When a <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process" title="multiprocessing.Process"><tt class="xref py py-class docutils literal"><span class="pre">Process</span></tt></a> object is created, it will inherit the
authentication key of its parent process, although this may be changed by
setting <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.authkey" title="multiprocessing.Process.authkey"><tt class="xref py py-attr docutils literal"><span class="pre">authkey</span></tt></a> to another byte string.</p>
<p>See <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-auth-keys"><em>Authentication keys</em></a>.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Process.terminate">
<tt class="descname">terminate</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.terminate" title="Permalink to this definition">¶</a></dt>
<dd><p>Terminate the process.  On Unix this is done using the <tt class="docutils literal"><span class="pre">SIGTERM</span></tt> signal;
on Windows <tt class="xref c c-func docutils literal"><span class="pre">TerminateProcess()</span></tt> is used.  Note that exit handlers and
finally clauses, etc., will not be executed.</p>
<p>Note that descendant processes of the process will <em>not</em> be terminated –
they will simply become orphaned.</p>
<div class="admonition warning">
<p class="first admonition-title">Warning</p>
<p class="last">If this method is used when the associated process is using a pipe or
queue then the pipe or queue is liable to become corrupted and may
become unusable by other process.  Similarly, if the process has
acquired a lock or semaphore etc. then terminating it is liable to
cause other processes to deadlock.</p>
</div>
</dd></dl>

<p>Note that the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.start" title="multiprocessing.Process.start"><tt class="xref py py-meth docutils literal"><span class="pre">start()</span></tt></a>, <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.join" title="multiprocessing.Process.join"><tt class="xref py py-meth docutils literal"><span class="pre">join()</span></tt></a>, <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.is_alive" title="multiprocessing.Process.is_alive"><tt class="xref py py-meth docutils literal"><span class="pre">is_alive()</span></tt></a>,
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.terminate" title="multiprocessing.Process.terminate"><tt class="xref py py-meth docutils literal"><span class="pre">terminate()</span></tt></a> and <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.exitcode" title="multiprocessing.Process.exitcode"><tt class="xref py py-attr docutils literal"><span class="pre">exitcode</span></tt></a> methods should only be called by
the process that created the process object.</p>
<p>Example usage of some of the methods of <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process" title="multiprocessing.Process"><tt class="xref py py-class docutils literal"><span class="pre">Process</span></tt></a>:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="kn">import</span> <span class="nn">multiprocessing</span><span class="o">,</span> <span class="nn">time</span><span class="o">,</span> <span class="nn">signal</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">p</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="mi">1000</span><span class="p">,))</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">print</span> <span class="n">p</span><span class="p">,</span> <span class="n">p</span><span class="o">.</span><span class="n">is_alive</span><span class="p">()</span>
<span class="go">&lt;Process(Process-1, initial)&gt; False</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">print</span> <span class="n">p</span><span class="p">,</span> <span class="n">p</span><span class="o">.</span><span class="n">is_alive</span><span class="p">()</span>
<span class="go">&lt;Process(Process-1, started)&gt; True</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">p</span><span class="o">.</span><span class="n">terminate</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">(</span><span class="mf">0.1</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">print</span> <span class="n">p</span><span class="p">,</span> <span class="n">p</span><span class="o">.</span><span class="n">is_alive</span><span class="p">()</span>
<span class="go">&lt;Process(Process-1, stopped[SIGTERM])&gt; False</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">p</span><span class="o">.</span><span class="n">exitcode</span> <span class="o">==</span> <span class="o">-</span><span class="n">signal</span><span class="o">.</span><span class="n">SIGTERM</span>
<span class="go">True</span>
</pre></div>
</div>
</dd></dl>

<dl class="exception">
<dt id="multiprocessing.BufferTooShort">
<em class="property">exception </em><tt class="descclassname">multiprocessing.</tt><tt class="descname">BufferTooShort</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.BufferTooShort" title="Permalink to this definition">¶</a></dt>
<dd><p>Exception raised by <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.recv_bytes_into" title="multiprocessing.Connection.recv_bytes_into"><tt class="xref py py-meth docutils literal"><span class="pre">Connection.recv_bytes_into()</span></tt></a> when the supplied
buffer object is too small for the message read.</p>
<p>If <tt class="docutils literal"><span class="pre">e</span></tt> is an instance of <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.BufferTooShort" title="multiprocessing.BufferTooShort"><tt class="xref py py-exc docutils literal"><span class="pre">BufferTooShort</span></tt></a> then <tt class="docutils literal"><span class="pre">e.args[0]</span></tt> will give
the message as a byte string.</p>
</dd></dl>

</div>
<div class="section" id="pipes-and-queues">
<h3>16.6.2.2. Pipes and Queues<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#pipes-and-queues" title="Permalink to this headline">¶</a></h3>
<p>When using multiple processes, one generally uses message passing for
communication between processes and avoids having to use any synchronization
primitives like locks.</p>
<p>For passing messages one can use <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Pipe" title="multiprocessing.Pipe"><tt class="xref py py-func docutils literal"><span class="pre">Pipe()</span></tt></a> (for a connection between two
processes) or a queue (which allows multiple producers and consumers).</p>
<p>The <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue" title="multiprocessing.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue</span></tt></a>, <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.multiprocessing.queues.SimpleQueue" title="multiprocessing.multiprocessing.queues.SimpleQueue"><tt class="xref py py-class docutils literal"><span class="pre">multiprocessing.queues.SimpleQueue</span></tt></a> and <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.JoinableQueue" title="multiprocessing.JoinableQueue"><tt class="xref py py-class docutils literal"><span class="pre">JoinableQueue</span></tt></a> types are multi-producer,
multi-consumer FIFO queues modelled on the <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Queue" title="Queue.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue.Queue</span></tt></a> class in the
standard library.  They differ in that <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue" title="multiprocessing.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue</span></tt></a> lacks the
<a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Queue.task_done" title="Queue.Queue.task_done"><tt class="xref py py-meth docutils literal"><span class="pre">task_done()</span></tt></a> and <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Queue.join" title="Queue.Queue.join"><tt class="xref py py-meth docutils literal"><span class="pre">join()</span></tt></a> methods introduced
into Python 2.5’s <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Queue" title="Queue.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue.Queue</span></tt></a> class.</p>
<p>If you use <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.JoinableQueue" title="multiprocessing.JoinableQueue"><tt class="xref py py-class docutils literal"><span class="pre">JoinableQueue</span></tt></a> then you <strong>must</strong> call
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.JoinableQueue.task_done" title="multiprocessing.JoinableQueue.task_done"><tt class="xref py py-meth docutils literal"><span class="pre">JoinableQueue.task_done()</span></tt></a> for each task removed from the queue or else the
semaphore used to count the number of unfinished tasks may eventually overflow,
raising an exception.</p>
<p>Note that one can also create a shared queue by using a manager object – see
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-managers"><em>Managers</em></a>.</p>
<div class="admonition note">
<p class="first admonition-title">Note</p>
<p class="last"><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> uses the usual <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Empty" title="Queue.Empty"><tt class="xref py py-exc docutils literal"><span class="pre">Queue.Empty</span></tt></a> and
<a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Full" title="Queue.Full"><tt class="xref py py-exc docutils literal"><span class="pre">Queue.Full</span></tt></a> exceptions to signal a timeout.  They are not available in
the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> namespace so you need to import them from
<a class="reference internal" href="http://docs.python.org/2/library/queue.html#module-Queue" title="Queue: A synchronized queue class."><tt class="xref py py-mod docutils literal"><span class="pre">Queue</span></tt></a>.</p>
</div>
<div class="admonition note">
<p class="first admonition-title">Note</p>
<p>When an object is put on a queue, the object is pickled and a
background thread later flushes the pickled data to an underlying
pipe.  This has some consequences which are a little surprising,
but should not cause any practical difficulties – if they really
bother you then you can instead use a queue created with a
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-managers"><em>manager</em></a>.</p>
<ol class="last arabic simple">
<li>After putting an object on an empty queue there may be an
infinitesimal delay before the queue’s <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.empty" title="multiprocessing.Queue.empty"><tt class="xref py py-meth docutils literal"><span class="pre">empty()</span></tt></a>
method returns <a class="reference internal" href="http://docs.python.org/2/library/constants.html#False" title="False"><tt class="xref py py-const xref docutils literal"><span class="pre">False</span></tt></a> and <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.get_nowait" title="multiprocessing.Queue.get_nowait"><tt class="xref py py-meth docutils literal"><span class="pre">get_nowait()</span></tt></a> can
return without raising <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Empty" title="Queue.Empty"><tt class="xref py py-exc docutils literal"><span class="pre">Queue.Empty</span></tt></a>.</li>
<li>If multiple processes are enqueuing objects, it is possible for
the objects to be received at the other end out-of-order.
However, objects enqueued by the same process will always be in
the expected order with respect to each other.</li>
</ol>
</div>
<div class="admonition warning">
<p class="first admonition-title">Warning</p>
<p class="last">If a process is killed using <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.terminate" title="multiprocessing.Process.terminate"><tt class="xref py py-meth docutils literal"><span class="pre">Process.terminate()</span></tt></a> or <a class="reference internal" href="http://docs.python.org/2/library/os.html#os.kill" title="os.kill"><tt class="xref py py-func docutils literal"><span class="pre">os.kill()</span></tt></a>
while it is trying to use a <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue" title="multiprocessing.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue</span></tt></a>, then the data in the queue is
likely to become corrupted.  This may cause any other process to get an
exception when it tries to use the queue later on.</p>
</div>
<div class="admonition warning">
<p class="first admonition-title">Warning</p>
<p>As mentioned above, if a child process has put items on a queue (and it has
not used <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.cancel_join_thread" title="multiprocessing.Queue.cancel_join_thread"><tt class="xref py py-meth docutils literal"><span class="pre">JoinableQueue.cancel_join_thread</span></tt></a>), then that process will
not terminate until all buffered items have been flushed to the pipe.</p>
<p>This means that if you try joining that process you may get a deadlock unless
you are sure that all items which have been put on the queue have been
consumed.  Similarly, if the child process is non-daemonic then the parent
process may hang on exit when it tries to join all its non-daemonic children.</p>
<p class="last">Note that a queue created using a manager does not have this issue.  See
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-programming"><em>Programming guidelines</em></a>.</p>
</div>
<p>For an example of the usage of queues for interprocess communication see
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-examples"><em>Examples</em></a>.</p>
<dl class="function">
<dt id="multiprocessing.Pipe">
<tt class="descclassname">multiprocessing.</tt><tt class="descname">Pipe</tt><big>(</big><span class="optional">[</span><em>duplex</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Pipe" title="Permalink to this definition">¶</a></dt>
<dd><p>Returns a pair <tt class="docutils literal"><span class="pre">(conn1,</span> <span class="pre">conn2)</span></tt> of <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection" title="multiprocessing.Connection"><tt class="xref py py-class docutils literal"><span class="pre">Connection</span></tt></a> objects representing
the ends of a pipe.</p>
<p>If <em>duplex</em> is <tt class="xref docutils literal"><span class="pre">True</span></tt> (the default) then the pipe is bidirectional.  If
<em>duplex</em> is <tt class="xref docutils literal"><span class="pre">False</span></tt> then the pipe is unidirectional: <tt class="docutils literal"><span class="pre">conn1</span></tt> can only be
used for receiving messages and <tt class="docutils literal"><span class="pre">conn2</span></tt> can only be used for sending
messages.</p>
</dd></dl>

<dl class="class">
<dt id="multiprocessing.Queue">
<em class="property">class </em><tt class="descclassname">multiprocessing.</tt><tt class="descname">Queue</tt><big>(</big><span class="optional">[</span><em>maxsize</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue" title="Permalink to this definition">¶</a></dt>
<dd><p>Returns a process shared queue implemented using a pipe and a few
locks/semaphores.  When a process first puts an item on the queue a feeder
thread is started which transfers objects from a buffer into the pipe.</p>
<p>The usual <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Empty" title="Queue.Empty"><tt class="xref py py-exc docutils literal"><span class="pre">Queue.Empty</span></tt></a> and <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Full" title="Queue.Full"><tt class="xref py py-exc docutils literal"><span class="pre">Queue.Full</span></tt></a> exceptions from the
standard library’s <a class="reference internal" href="http://docs.python.org/2/library/queue.html#module-Queue" title="Queue: A synchronized queue class."><tt class="xref py py-mod docutils literal"><span class="pre">Queue</span></tt></a> module are raised to signal timeouts.</p>
<p><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue" title="multiprocessing.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue</span></tt></a> implements all the methods of <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Queue" title="Queue.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue.Queue</span></tt></a> except for
<a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Queue.task_done" title="Queue.Queue.task_done"><tt class="xref py py-meth docutils literal"><span class="pre">task_done()</span></tt></a> and <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Queue.join" title="Queue.Queue.join"><tt class="xref py py-meth docutils literal"><span class="pre">join()</span></tt></a>.</p>
<dl class="method">
<dt id="multiprocessing.Queue.qsize">
<tt class="descname">qsize</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.qsize" title="Permalink to this definition">¶</a></dt>
<dd><p>Return the approximate size of the queue.  Because of
multithreading/multiprocessing semantics, this number is not reliable.</p>
<p>Note that this may raise <a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.NotImplementedError" title="exceptions.NotImplementedError"><tt class="xref py py-exc docutils literal"><span class="pre">NotImplementedError</span></tt></a> on Unix platforms like
Mac OS X where <tt class="docutils literal"><span class="pre">sem_getvalue()</span></tt> is not implemented.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Queue.empty">
<tt class="descname">empty</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.empty" title="Permalink to this definition">¶</a></dt>
<dd><p>Return <tt class="xref docutils literal"><span class="pre">True</span></tt> if the queue is empty, <tt class="xref docutils literal"><span class="pre">False</span></tt> otherwise.  Because of
multithreading/multiprocessing semantics, this is not reliable.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Queue.full">
<tt class="descname">full</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.full" title="Permalink to this definition">¶</a></dt>
<dd><p>Return <tt class="xref docutils literal"><span class="pre">True</span></tt> if the queue is full, <tt class="xref docutils literal"><span class="pre">False</span></tt> otherwise.  Because of
multithreading/multiprocessing semantics, this is not reliable.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Queue.put">
<tt class="descname">put</tt><big>(</big><em>obj</em><span class="optional">[</span>, <em>block</em><span class="optional">[</span>, <em>timeout</em><span class="optional">]</span><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.put" title="Permalink to this definition">¶</a></dt>
<dd><p>Put obj into the queue.  If the optional argument <em>block</em> is <tt class="xref docutils literal"><span class="pre">True</span></tt>
(the default) and <em>timeout</em> is <tt class="xref docutils literal"><span class="pre">None</span></tt> (the default), block if necessary until
a free slot is available.  If <em>timeout</em> is a positive number, it blocks at
most <em>timeout</em> seconds and raises the <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Full" title="Queue.Full"><tt class="xref py py-exc docutils literal"><span class="pre">Queue.Full</span></tt></a> exception if no
free slot was available within that time.  Otherwise (<em>block</em> is
<tt class="xref docutils literal"><span class="pre">False</span></tt>), put an item on the queue if a free slot is immediately
available, else raise the <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Full" title="Queue.Full"><tt class="xref py py-exc docutils literal"><span class="pre">Queue.Full</span></tt></a> exception (<em>timeout</em> is
ignored in that case).</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Queue.put_nowait">
<tt class="descname">put_nowait</tt><big>(</big><em>obj</em><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.put_nowait" title="Permalink to this definition">¶</a></dt>
<dd><p>Equivalent to <tt class="docutils literal"><span class="pre">put(obj,</span> <span class="pre">False)</span></tt>.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Queue.get">
<tt class="descname">get</tt><big>(</big><span class="optional">[</span><em>block</em><span class="optional">[</span>, <em>timeout</em><span class="optional">]</span><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.get" title="Permalink to this definition">¶</a></dt>
<dd><p>Remove and return an item from the queue.  If optional args <em>block</em> is
<tt class="xref docutils literal"><span class="pre">True</span></tt> (the default) and <em>timeout</em> is <tt class="xref docutils literal"><span class="pre">None</span></tt> (the default), block if
necessary until an item is available.  If <em>timeout</em> is a positive number,
it blocks at most <em>timeout</em> seconds and raises the <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Empty" title="Queue.Empty"><tt class="xref py py-exc docutils literal"><span class="pre">Queue.Empty</span></tt></a>
exception if no item was available within that time.  Otherwise (block is
<tt class="xref docutils literal"><span class="pre">False</span></tt>), return an item if one is immediately available, else raise the
<a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Empty" title="Queue.Empty"><tt class="xref py py-exc docutils literal"><span class="pre">Queue.Empty</span></tt></a> exception (<em>timeout</em> is ignored in that case).</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Queue.get_nowait">
<tt class="descname">get_nowait</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.get_nowait" title="Permalink to this definition">¶</a></dt>
<dd><p>Equivalent to <tt class="docutils literal"><span class="pre">get(False)</span></tt>.</p>
</dd></dl>

<p><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue" title="multiprocessing.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue</span></tt></a> has a few additional methods not found in
<a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Queue" title="Queue.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue.Queue</span></tt></a>.  These methods are usually unnecessary for most
code:</p>
<dl class="method">
<dt id="multiprocessing.Queue.close">
<tt class="descname">close</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.close" title="Permalink to this definition">¶</a></dt>
<dd><p>Indicate that no more data will be put on this queue by the current
process.  The background thread will quit once it has flushed all buffered
data to the pipe.  This is called automatically when the queue is garbage
collected.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Queue.join_thread">
<tt class="descname">join_thread</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.join_thread" title="Permalink to this definition">¶</a></dt>
<dd><p>Join the background thread.  This can only be used after <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.close" title="multiprocessing.Queue.close"><tt class="xref py py-meth docutils literal"><span class="pre">close()</span></tt></a> has
been called.  It blocks until the background thread exits, ensuring that
all data in the buffer has been flushed to the pipe.</p>
<p>By default if a process is not the creator of the queue then on exit it
will attempt to join the queue’s background thread.  The process can call
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.cancel_join_thread" title="multiprocessing.Queue.cancel_join_thread"><tt class="xref py py-meth docutils literal"><span class="pre">cancel_join_thread()</span></tt></a> to make <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.join_thread" title="multiprocessing.Queue.join_thread"><tt class="xref py py-meth docutils literal"><span class="pre">join_thread()</span></tt></a> do nothing.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Queue.cancel_join_thread">
<tt class="descname">cancel_join_thread</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.cancel_join_thread" title="Permalink to this definition">¶</a></dt>
<dd><p>Prevent <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.join_thread" title="multiprocessing.Queue.join_thread"><tt class="xref py py-meth docutils literal"><span class="pre">join_thread()</span></tt></a> from blocking.  In particular, this prevents
the background thread from being joined automatically when the process
exits – see <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.join_thread" title="multiprocessing.Queue.join_thread"><tt class="xref py py-meth docutils literal"><span class="pre">join_thread()</span></tt></a>.</p>
<p>A better name for this method might be
<tt class="docutils literal"><span class="pre">allow_exit_without_flush()</span></tt>.  It is likely to cause enqueued
data to lost, and you almost certainly will not need to use it.
It is really only there if you need the current process to exit
immediately without waiting to flush enqueued data to the
underlying pipe, and you don’t care about lost data.</p>
</dd></dl>

</dd></dl>

<dl class="class">
<dt id="multiprocessing.multiprocessing.queues.SimpleQueue">
<em class="property">class </em><tt class="descclassname">multiprocessing.queues.</tt><tt class="descname">SimpleQueue</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.multiprocessing.queues.SimpleQueue" title="Permalink to this definition">¶</a></dt>
<dd><p>It is a simplified <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue" title="multiprocessing.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue</span></tt></a> type, very close to a locked <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Pipe" title="multiprocessing.Pipe"><tt class="xref py py-class docutils literal"><span class="pre">Pipe</span></tt></a>.</p>
<dl class="method">
<dt id="multiprocessing.multiprocessing.queues.SimpleQueue.empty">
<tt class="descname">empty</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.multiprocessing.queues.SimpleQueue.empty" title="Permalink to this definition">¶</a></dt>
<dd><p>Return <tt class="xref docutils literal"><span class="pre">True</span></tt> if the queue is empty, <tt class="xref docutils literal"><span class="pre">False</span></tt> otherwise.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.multiprocessing.queues.SimpleQueue.get">
<tt class="descname">get</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.multiprocessing.queues.SimpleQueue.get" title="Permalink to this definition">¶</a></dt>
<dd><p>Remove and return an item from the queue.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.multiprocessing.queues.SimpleQueue.put">
<tt class="descname">put</tt><big>(</big><em>item</em><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.multiprocessing.queues.SimpleQueue.put" title="Permalink to this definition">¶</a></dt>
<dd><p>Put <em>item</em> into the queue.</p>
</dd></dl>

</dd></dl>

<dl class="class">
<dt id="multiprocessing.JoinableQueue">
<em class="property">class </em><tt class="descclassname">multiprocessing.</tt><tt class="descname">JoinableQueue</tt><big>(</big><span class="optional">[</span><em>maxsize</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.JoinableQueue" title="Permalink to this definition">¶</a></dt>
<dd><p><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.JoinableQueue" title="multiprocessing.JoinableQueue"><tt class="xref py py-class docutils literal"><span class="pre">JoinableQueue</span></tt></a>, a <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue" title="multiprocessing.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue</span></tt></a> subclass, is a queue which
additionally has <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.JoinableQueue.task_done" title="multiprocessing.JoinableQueue.task_done"><tt class="xref py py-meth docutils literal"><span class="pre">task_done()</span></tt></a> and <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.JoinableQueue.join" title="multiprocessing.JoinableQueue.join"><tt class="xref py py-meth docutils literal"><span class="pre">join()</span></tt></a> methods.</p>
<dl class="method">
<dt id="multiprocessing.JoinableQueue.task_done">
<tt class="descname">task_done</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.JoinableQueue.task_done" title="Permalink to this definition">¶</a></dt>
<dd><p>Indicate that a formerly enqueued task is complete. Used by queue consumer
threads.  For each <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.get" title="multiprocessing.Queue.get"><tt class="xref py py-meth docutils literal"><span class="pre">get()</span></tt></a> used to fetch a task, a subsequent
call to <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.JoinableQueue.task_done" title="multiprocessing.JoinableQueue.task_done"><tt class="xref py py-meth docutils literal"><span class="pre">task_done()</span></tt></a> tells the queue that the processing on the task
is complete.</p>
<p>If a <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Queue.join" title="Queue.Queue.join"><tt class="xref py py-meth docutils literal"><span class="pre">join()</span></tt></a> is currently blocking, it will resume when all
items have been processed (meaning that a <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.JoinableQueue.task_done" title="multiprocessing.JoinableQueue.task_done"><tt class="xref py py-meth docutils literal"><span class="pre">task_done()</span></tt></a> call was
received for every item that had been <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.put" title="multiprocessing.Queue.put"><tt class="xref py py-meth docutils literal"><span class="pre">put()</span></tt></a> into the queue).</p>
<p>Raises a <a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.ValueError" title="exceptions.ValueError"><tt class="xref py py-exc docutils literal"><span class="pre">ValueError</span></tt></a> if called more times than there were items
placed in the queue.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.JoinableQueue.join">
<tt class="descname">join</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.JoinableQueue.join" title="Permalink to this definition">¶</a></dt>
<dd><p>Block until all items in the queue have been gotten and processed.</p>
<p>The count of unfinished tasks goes up whenever an item is added to the
queue.  The count goes down whenever a consumer thread calls
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.JoinableQueue.task_done" title="multiprocessing.JoinableQueue.task_done"><tt class="xref py py-meth docutils literal"><span class="pre">task_done()</span></tt></a> to indicate that the item was retrieved and all work on
it is complete.  When the count of unfinished tasks drops to zero,
<a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Queue.join" title="Queue.Queue.join"><tt class="xref py py-meth docutils literal"><span class="pre">join()</span></tt></a> unblocks.</p>
</dd></dl>

</dd></dl>

</div>
<div class="section" id="miscellaneous">
<h3>16.6.2.3. Miscellaneous<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#miscellaneous" title="Permalink to this headline">¶</a></h3>
<dl class="function">
<dt id="multiprocessing.active_children">
<tt class="descclassname">multiprocessing.</tt><tt class="descname">active_children</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.active_children" title="Permalink to this definition">¶</a></dt>
<dd><p>Return list of all live children of the current process.</p>
<p>Calling this has the side affect of “joining” any processes which have
already finished.</p>
</dd></dl>

<dl class="function">
<dt id="multiprocessing.cpu_count">
<tt class="descclassname">multiprocessing.</tt><tt class="descname">cpu_count</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.cpu_count" title="Permalink to this definition">¶</a></dt>
<dd><p>Return the number of CPUs in the system.  May raise
<a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.NotImplementedError" title="exceptions.NotImplementedError"><tt class="xref py py-exc docutils literal"><span class="pre">NotImplementedError</span></tt></a>.</p>
</dd></dl>

<dl class="function">
<dt id="multiprocessing.current_process">
<tt class="descclassname">multiprocessing.</tt><tt class="descname">current_process</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.current_process" title="Permalink to this definition">¶</a></dt>
<dd><p>Return the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process" title="multiprocessing.Process"><tt class="xref py py-class docutils literal"><span class="pre">Process</span></tt></a> object corresponding to the current process.</p>
<p>An analogue of <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.current_thread" title="threading.current_thread"><tt class="xref py py-func docutils literal"><span class="pre">threading.current_thread()</span></tt></a>.</p>
</dd></dl>

<dl class="function">
<dt id="multiprocessing.freeze_support">
<tt class="descclassname">multiprocessing.</tt><tt class="descname">freeze_support</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.freeze_support" title="Permalink to this definition">¶</a></dt>
<dd><p>Add support for when a program which uses <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> has been
frozen to produce a Windows executable.  (Has been tested with <strong>py2exe</strong>,
<strong>PyInstaller</strong> and <strong>cx_Freeze</strong>.)</p>
<p>One needs to call this function straight after the <tt class="docutils literal"><span class="pre">if</span> <span class="pre">__name__</span> <span class="pre">==</span>
<span class="pre">'__main__'</span></tt> line of the main module.  For example:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">freeze_support</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">():</span>
    <span class="k">print</span> <span class="s">'hello world!'</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">freeze_support</span><span class="p">()</span>
    <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">f</span><span class="p">)</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
</pre></div>
</div>
<p>If the <tt class="docutils literal"><span class="pre">freeze_support()</span></tt> line is omitted then trying to run the frozen
executable will raise <a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.RuntimeError" title="exceptions.RuntimeError"><tt class="xref py py-exc docutils literal"><span class="pre">RuntimeError</span></tt></a>.</p>
<p>If the module is being run normally by the Python interpreter then
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.freeze_support" title="multiprocessing.freeze_support"><tt class="xref py py-func docutils literal"><span class="pre">freeze_support()</span></tt></a> has no effect.</p>
</dd></dl>

<dl class="function">
<dt id="multiprocessing.set_executable">
<tt class="descclassname">multiprocessing.</tt><tt class="descname">set_executable</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.set_executable" title="Permalink to this definition">¶</a></dt>
<dd><p>Sets the path of the Python interpreter to use when starting a child process.
(By default <a class="reference internal" href="http://docs.python.org/2/library/sys.html#sys.executable" title="sys.executable"><tt class="xref py py-data docutils literal"><span class="pre">sys.executable</span></tt></a> is used).  Embedders will probably need to
do some thing like</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="n">set_executable</span><span class="p">(</span><span class="n">os</span><span class="o">.</span><span class="n">path</span><span class="o">.</span><span class="n">join</span><span class="p">(</span><span class="n">sys</span><span class="o">.</span><span class="n">exec_prefix</span><span class="p">,</span> <span class="s">'pythonw.exe'</span><span class="p">))</span>
</pre></div>
</div>
<p>before they can create child processes.  (Windows only)</p>
</dd></dl>

<div class="admonition note">
<p class="first admonition-title">Note</p>
<p class="last"><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> contains no analogues of
<a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.active_count" title="threading.active_count"><tt class="xref py py-func docutils literal"><span class="pre">threading.active_count()</span></tt></a>, <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.enumerate" title="threading.enumerate"><tt class="xref py py-func docutils literal"><span class="pre">threading.enumerate()</span></tt></a>,
<a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.settrace" title="threading.settrace"><tt class="xref py py-func docutils literal"><span class="pre">threading.settrace()</span></tt></a>, <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.setprofile" title="threading.setprofile"><tt class="xref py py-func docutils literal"><span class="pre">threading.setprofile()</span></tt></a>,
<a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Timer" title="threading.Timer"><tt class="xref py py-class docutils literal"><span class="pre">threading.Timer</span></tt></a>, or <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.local" title="threading.local"><tt class="xref py py-class docutils literal"><span class="pre">threading.local</span></tt></a>.</p>
</div>
</div>
<div class="section" id="connection-objects">
<h3>16.6.2.4. Connection Objects<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#connection-objects" title="Permalink to this headline">¶</a></h3>
<p>Connection objects allow the sending and receiving of picklable objects or
strings.  They can be thought of as message oriented connected sockets.</p>
<p>Connection objects are usually created using <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Pipe" title="multiprocessing.Pipe"><tt class="xref py py-func docutils literal"><span class="pre">Pipe()</span></tt></a> – see also
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-listeners-clients"><em>Listeners and Clients</em></a>.</p>
<dl class="class">
<dt id="multiprocessing.Connection">
<em class="property">class </em><tt class="descclassname">multiprocessing.</tt><tt class="descname">Connection</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection" title="Permalink to this definition">¶</a></dt>
<dd><dl class="method">
<dt id="multiprocessing.Connection.send">
<tt class="descname">send</tt><big>(</big><em>obj</em><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.send" title="Permalink to this definition">¶</a></dt>
<dd><p>Send an object to the other end of the connection which should be read
using <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.recv" title="multiprocessing.Connection.recv"><tt class="xref py py-meth docutils literal"><span class="pre">recv()</span></tt></a>.</p>
<p>The object must be picklable.  Very large pickles (approximately 32 MB+,
though it depends on the OS) may raise a <a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.ValueError" title="exceptions.ValueError"><tt class="xref py py-exc docutils literal"><span class="pre">ValueError</span></tt></a> exception.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Connection.recv">
<tt class="descname">recv</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.recv" title="Permalink to this definition">¶</a></dt>
<dd><p>Return an object sent from the other end of the connection using
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.send" title="multiprocessing.Connection.send"><tt class="xref py py-meth docutils literal"><span class="pre">send()</span></tt></a>.  Blocks until there its something to receive.  Raises
<a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.EOFError" title="exceptions.EOFError"><tt class="xref py py-exc docutils literal"><span class="pre">EOFError</span></tt></a> if there is nothing left to receive
and the other end was closed.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Connection.fileno">
<tt class="descname">fileno</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.fileno" title="Permalink to this definition">¶</a></dt>
<dd><p>Return the file descriptor or handle used by the connection.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Connection.close">
<tt class="descname">close</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.close" title="Permalink to this definition">¶</a></dt>
<dd><p>Close the connection.</p>
<p>This is called automatically when the connection is garbage collected.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Connection.poll">
<tt class="descname">poll</tt><big>(</big><span class="optional">[</span><em>timeout</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.poll" title="Permalink to this definition">¶</a></dt>
<dd><p>Return whether there is any data available to be read.</p>
<p>If <em>timeout</em> is not specified then it will return immediately.  If
<em>timeout</em> is a number then this specifies the maximum time in seconds to
block.  If <em>timeout</em> is <tt class="xref docutils literal"><span class="pre">None</span></tt> then an infinite timeout is used.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Connection.send_bytes">
<tt class="descname">send_bytes</tt><big>(</big><em>buffer</em><span class="optional">[</span>, <em>offset</em><span class="optional">[</span>, <em>size</em><span class="optional">]</span><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.send_bytes" title="Permalink to this definition">¶</a></dt>
<dd><p>Send byte data from an object supporting the buffer interface as a
complete message.</p>
<p>If <em>offset</em> is given then data is read from that position in <em>buffer</em>.  If
<em>size</em> is given then that many bytes will be read from buffer.  Very large
buffers (approximately 32 MB+, though it depends on the OS) may raise a
<a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.ValueError" title="exceptions.ValueError"><tt class="xref py py-exc docutils literal"><span class="pre">ValueError</span></tt></a> exception</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Connection.recv_bytes">
<tt class="descname">recv_bytes</tt><big>(</big><span class="optional">[</span><em>maxlength</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.recv_bytes" title="Permalink to this definition">¶</a></dt>
<dd><p>Return a complete message of byte data sent from the other end of the
connection as a string.  Blocks until there is something to receive.
Raises <a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.EOFError" title="exceptions.EOFError"><tt class="xref py py-exc docutils literal"><span class="pre">EOFError</span></tt></a> if there is nothing left
to receive and the other end has closed.</p>
<p>If <em>maxlength</em> is specified and the message is longer than <em>maxlength</em>
then <a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.IOError" title="exceptions.IOError"><tt class="xref py py-exc docutils literal"><span class="pre">IOError</span></tt></a> is raised and the connection will no longer be
readable.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.Connection.recv_bytes_into">
<tt class="descname">recv_bytes_into</tt><big>(</big><em>buffer</em><span class="optional">[</span>, <em>offset</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.recv_bytes_into" title="Permalink to this definition">¶</a></dt>
<dd><p>Read into <em>buffer</em> a complete message of byte data sent from the other end
of the connection and return the number of bytes in the message.  Blocks
until there is something to receive.  Raises
<a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.EOFError" title="exceptions.EOFError"><tt class="xref py py-exc docutils literal"><span class="pre">EOFError</span></tt></a> if there is nothing left to receive and the other end was
closed.</p>
<p><em>buffer</em> must be an object satisfying the writable buffer interface.  If
<em>offset</em> is given then the message will be written into the buffer from
that position.  Offset must be a non-negative integer less than the
length of <em>buffer</em> (in bytes).</p>
<p>If the buffer is too short then a <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.BufferTooShort" title="multiprocessing.BufferTooShort"><tt class="xref py py-exc docutils literal"><span class="pre">BufferTooShort</span></tt></a> exception is
raised and the complete message is available as <tt class="docutils literal"><span class="pre">e.args[0]</span></tt> where <tt class="docutils literal"><span class="pre">e</span></tt>
is the exception instance.</p>
</dd></dl>

</dd></dl>

<p>For example:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Pipe</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">a</span><span class="p">,</span> <span class="n">b</span> <span class="o">=</span> <span class="n">Pipe</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">a</span><span class="o">.</span><span class="n">send</span><span class="p">([</span><span class="mi">1</span><span class="p">,</span> <span class="s">'hello'</span><span class="p">,</span> <span class="bp">None</span><span class="p">])</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">b</span><span class="o">.</span><span class="n">recv</span><span class="p">()</span>
<span class="go">[1, 'hello', None]</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">b</span><span class="o">.</span><span class="n">send_bytes</span><span class="p">(</span><span class="s">'thank you'</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">a</span><span class="o">.</span><span class="n">recv_bytes</span><span class="p">()</span>
<span class="go">'thank you'</span>
<span class="gp">&gt;&gt;&gt; </span><span class="kn">import</span> <span class="nn">array</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">arr1</span> <span class="o">=</span> <span class="n">array</span><span class="o">.</span><span class="n">array</span><span class="p">(</span><span class="s">'i'</span><span class="p">,</span> <span class="nb">range</span><span class="p">(</span><span class="mi">5</span><span class="p">))</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">arr2</span> <span class="o">=</span> <span class="n">array</span><span class="o">.</span><span class="n">array</span><span class="p">(</span><span class="s">'i'</span><span class="p">,</span> <span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">*</span> <span class="mi">10</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">a</span><span class="o">.</span><span class="n">send_bytes</span><span class="p">(</span><span class="n">arr1</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">count</span> <span class="o">=</span> <span class="n">b</span><span class="o">.</span><span class="n">recv_bytes_into</span><span class="p">(</span><span class="n">arr2</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">assert</span> <span class="n">count</span> <span class="o">==</span> <span class="nb">len</span><span class="p">(</span><span class="n">arr1</span><span class="p">)</span> <span class="o">*</span> <span class="n">arr1</span><span class="o">.</span><span class="n">itemsize</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">arr2</span>
<span class="go">array('i', [0, 1, 2, 3, 4, 0, 0, 0, 0, 0])</span>
</pre></div>
</div>
<div class="admonition warning">
<p class="first admonition-title">Warning</p>
<p>The <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.recv" title="multiprocessing.Connection.recv"><tt class="xref py py-meth docutils literal"><span class="pre">Connection.recv()</span></tt></a> method automatically unpickles the data it
receives, which can be a security risk unless you can trust the process
which sent the message.</p>
<p class="last">Therefore, unless the connection object was produced using <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Pipe" title="multiprocessing.Pipe"><tt class="xref py py-func docutils literal"><span class="pre">Pipe()</span></tt></a> you
should only use the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.recv" title="multiprocessing.Connection.recv"><tt class="xref py py-meth docutils literal"><span class="pre">recv()</span></tt></a> and <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.send" title="multiprocessing.Connection.send"><tt class="xref py py-meth docutils literal"><span class="pre">send()</span></tt></a>
methods after performing some sort of authentication.  See
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-auth-keys"><em>Authentication keys</em></a>.</p>
</div>
<div class="admonition warning">
<p class="first admonition-title">Warning</p>
<p class="last">If a process is killed while it is trying to read or write to a pipe then
the data in the pipe is likely to become corrupted, because it may become
impossible to be sure where the message boundaries lie.</p>
</div>
</div>
<div class="section" id="synchronization-primitives">
<h3>16.6.2.5. Synchronization primitives<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#synchronization-primitives" title="Permalink to this headline">¶</a></h3>
<p>Generally synchronization primitives are not as necessary in a multiprocess
program as they are in a multithreaded program.  See the documentation for
<a class="reference internal" href="http://docs.python.org/2/library/threading.html#module-threading" title="threading: Higher-level threading interface."><tt class="xref py py-mod docutils literal"><span class="pre">threading</span></tt></a> module.</p>
<p>Note that one can also create synchronization primitives by using a manager
object – see <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-managers"><em>Managers</em></a>.</p>
<dl class="class">
<dt id="multiprocessing.BoundedSemaphore">
<em class="property">class </em><tt class="descclassname">multiprocessing.</tt><tt class="descname">BoundedSemaphore</tt><big>(</big><span class="optional">[</span><em>value</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.BoundedSemaphore" title="Permalink to this definition">¶</a></dt>
<dd><p>A bounded semaphore object: a clone of <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.BoundedSemaphore" title="threading.BoundedSemaphore"><tt class="xref py py-class docutils literal"><span class="pre">threading.BoundedSemaphore</span></tt></a>.</p>
<p>(On Mac OS X, this is indistinguishable from <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Semaphore" title="multiprocessing.Semaphore"><tt class="xref py py-class docutils literal"><span class="pre">Semaphore</span></tt></a> because
<tt class="docutils literal"><span class="pre">sem_getvalue()</span></tt> is not implemented on that platform).</p>
</dd></dl>

<dl class="class">
<dt id="multiprocessing.Condition">
<em class="property">class </em><tt class="descclassname">multiprocessing.</tt><tt class="descname">Condition</tt><big>(</big><span class="optional">[</span><em>lock</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Condition" title="Permalink to this definition">¶</a></dt>
<dd><p>A condition variable: a clone of <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Condition" title="threading.Condition"><tt class="xref py py-class docutils literal"><span class="pre">threading.Condition</span></tt></a>.</p>
<p>If <em>lock</em> is specified then it should be a <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Lock" title="multiprocessing.Lock"><tt class="xref py py-class docutils literal"><span class="pre">Lock</span></tt></a> or <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.RLock" title="multiprocessing.RLock"><tt class="xref py py-class docutils literal"><span class="pre">RLock</span></tt></a>
object from <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a>.</p>
</dd></dl>

<dl class="class">
<dt id="multiprocessing.Event">
<em class="property">class </em><tt class="descclassname">multiprocessing.</tt><tt class="descname">Event</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Event" title="Permalink to this definition">¶</a></dt>
<dd><p>A clone of <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Event" title="threading.Event"><tt class="xref py py-class docutils literal"><span class="pre">threading.Event</span></tt></a>.
This method returns the state of the internal semaphore on exit, so it
will always return <tt class="xref docutils literal"><span class="pre">True</span></tt> except if a timeout is given and the operation
times out.</p>
<p class="versionchanged">
<span class="versionmodified">Changed in version 2.7: </span>Previously, the method always returned <tt class="xref docutils literal"><span class="pre">None</span></tt>.</p>
</dd></dl>

<dl class="class">
<dt id="multiprocessing.Lock">
<em class="property">class </em><tt class="descclassname">multiprocessing.</tt><tt class="descname">Lock</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Lock" title="Permalink to this definition">¶</a></dt>
<dd><p>A non-recursive lock object: a clone of <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Lock" title="threading.Lock"><tt class="xref py py-class docutils literal"><span class="pre">threading.Lock</span></tt></a>.</p>
</dd></dl>

<dl class="class">
<dt id="multiprocessing.RLock">
<em class="property">class </em><tt class="descclassname">multiprocessing.</tt><tt class="descname">RLock</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.RLock" title="Permalink to this definition">¶</a></dt>
<dd><p>A recursive lock object: a clone of <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.RLock" title="threading.RLock"><tt class="xref py py-class docutils literal"><span class="pre">threading.RLock</span></tt></a>.</p>
</dd></dl>

<dl class="class">
<dt id="multiprocessing.Semaphore">
<em class="property">class </em><tt class="descclassname">multiprocessing.</tt><tt class="descname">Semaphore</tt><big>(</big><span class="optional">[</span><em>value</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Semaphore" title="Permalink to this definition">¶</a></dt>
<dd><p>A semaphore object: a clone of <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Semaphore" title="threading.Semaphore"><tt class="xref py py-class docutils literal"><span class="pre">threading.Semaphore</span></tt></a>.</p>
</dd></dl>

<div class="admonition note">
<p class="first admonition-title">Note</p>
<p>The <tt class="xref py py-meth docutils literal"><span class="pre">acquire()</span></tt> method of <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.BoundedSemaphore" title="multiprocessing.BoundedSemaphore"><tt class="xref py py-class docutils literal"><span class="pre">BoundedSemaphore</span></tt></a>, <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Lock" title="multiprocessing.Lock"><tt class="xref py py-class docutils literal"><span class="pre">Lock</span></tt></a>,
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.RLock" title="multiprocessing.RLock"><tt class="xref py py-class docutils literal"><span class="pre">RLock</span></tt></a> and <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Semaphore" title="multiprocessing.Semaphore"><tt class="xref py py-class docutils literal"><span class="pre">Semaphore</span></tt></a> has a timeout parameter not supported
by the equivalents in <a class="reference internal" href="http://docs.python.org/2/library/threading.html#module-threading" title="threading: Higher-level threading interface."><tt class="xref py py-mod docutils literal"><span class="pre">threading</span></tt></a>.  The signature is
<tt class="docutils literal"><span class="pre">acquire(block=True,</span> <span class="pre">timeout=None)</span></tt> with keyword parameters being
acceptable.  If <em>block</em> is <tt class="xref docutils literal"><span class="pre">True</span></tt> and <em>timeout</em> is not <tt class="xref docutils literal"><span class="pre">None</span></tt> then it
specifies a timeout in seconds.  If <em>block</em> is <tt class="xref docutils literal"><span class="pre">False</span></tt> then <em>timeout</em> is
ignored.</p>
<p class="last">On Mac OS X, <tt class="docutils literal"><span class="pre">sem_timedwait</span></tt> is unsupported, so calling <tt class="docutils literal"><span class="pre">acquire()</span></tt> with
a timeout will emulate that function’s behavior using a sleeping loop.</p>
</div>
<div class="admonition note">
<p class="first admonition-title">Note</p>
<p>If the SIGINT signal generated by Ctrl-C arrives while the main thread is
blocked by a call to <tt class="xref py py-meth docutils literal"><span class="pre">BoundedSemaphore.acquire()</span></tt>, <tt class="xref py py-meth docutils literal"><span class="pre">Lock.acquire()</span></tt>,
<tt class="xref py py-meth docutils literal"><span class="pre">RLock.acquire()</span></tt>, <tt class="xref py py-meth docutils literal"><span class="pre">Semaphore.acquire()</span></tt>, <tt class="xref py py-meth docutils literal"><span class="pre">Condition.acquire()</span></tt>
or <tt class="xref py py-meth docutils literal"><span class="pre">Condition.wait()</span></tt> then the call will be immediately interrupted and
<a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.KeyboardInterrupt" title="exceptions.KeyboardInterrupt"><tt class="xref py py-exc docutils literal"><span class="pre">KeyboardInterrupt</span></tt></a> will be raised.</p>
<p class="last">This differs from the behaviour of <a class="reference internal" href="http://docs.python.org/2/library/threading.html#module-threading" title="threading: Higher-level threading interface."><tt class="xref py py-mod docutils literal"><span class="pre">threading</span></tt></a> where SIGINT will be
ignored while the equivalent blocking calls are in progress.</p>
</div>
</div>
<div class="section" id="shared-ctypes-objects">
<h3>16.6.2.6. Shared <a class="reference internal" href="http://docs.python.org/2/library/ctypes.html#module-ctypes" title="ctypes: A foreign function library for Python."><tt class="xref py py-mod docutils literal"><span class="pre">ctypes</span></tt></a> Objects<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#shared-ctypes-objects" title="Permalink to this headline">¶</a></h3>
<p>It is possible to create shared objects using shared memory which can be
inherited by child processes.</p>
<dl class="function">
<dt id="multiprocessing.Value">
<tt class="descclassname">multiprocessing.</tt><tt class="descname">Value</tt><big>(</big><em>typecode_or_type</em>, <em>*args</em><span class="optional">[</span>, <em>lock</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Value" title="Permalink to this definition">¶</a></dt>
<dd><p>Return a <a class="reference internal" href="http://docs.python.org/2/library/ctypes.html#module-ctypes" title="ctypes: A foreign function library for Python."><tt class="xref py py-mod docutils literal"><span class="pre">ctypes</span></tt></a> object allocated from shared memory.  By default the
return value is actually a synchronized wrapper for the object.</p>
<p><em>typecode_or_type</em> determines the type of the returned object: it is either a
ctypes type or a one character typecode of the kind used by the <a class="reference internal" href="http://docs.python.org/2/library/array.html#module-array" title="array: Space efficient arrays of uniformly typed numeric values."><tt class="xref py py-mod docutils literal"><span class="pre">array</span></tt></a>
module.  <em>*args</em> is passed on to the constructor for the type.</p>
<p>If <em>lock</em> is <tt class="xref docutils literal"><span class="pre">True</span></tt> (the default) then a new lock object is created to
synchronize access to the value.  If <em>lock</em> is a <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Lock" title="multiprocessing.Lock"><tt class="xref py py-class docutils literal"><span class="pre">Lock</span></tt></a> or
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.RLock" title="multiprocessing.RLock"><tt class="xref py py-class docutils literal"><span class="pre">RLock</span></tt></a> object then that will be used to synchronize access to the
value.  If <em>lock</em> is <tt class="xref docutils literal"><span class="pre">False</span></tt> then access to the returned object will not be
automatically protected by a lock, so it will not necessarily be
“process-safe”.</p>
<p>Note that <em>lock</em> is a keyword-only argument.</p>
</dd></dl>

<dl class="function">
<dt id="multiprocessing.Array">
<tt class="descclassname">multiprocessing.</tt><tt class="descname">Array</tt><big>(</big><em>typecode_or_type</em>, <em>size_or_initializer</em>, <em>*</em>, <em>lock=True</em><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Array" title="Permalink to this definition">¶</a></dt>
<dd><p>Return a ctypes array allocated from shared memory.  By default the return
value is actually a synchronized wrapper for the array.</p>
<p><em>typecode_or_type</em> determines the type of the elements of the returned array:
it is either a ctypes type or a one character typecode of the kind used by
the <a class="reference internal" href="http://docs.python.org/2/library/array.html#module-array" title="array: Space efficient arrays of uniformly typed numeric values."><tt class="xref py py-mod docutils literal"><span class="pre">array</span></tt></a> module.  If <em>size_or_initializer</em> is an integer, then it
determines the length of the array, and the array will be initially zeroed.
Otherwise, <em>size_or_initializer</em> is a sequence which is used to initialize
the array and whose length determines the length of the array.</p>
<p>If <em>lock</em> is <tt class="xref docutils literal"><span class="pre">True</span></tt> (the default) then a new lock object is created to
synchronize access to the value.  If <em>lock</em> is a <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Lock" title="multiprocessing.Lock"><tt class="xref py py-class docutils literal"><span class="pre">Lock</span></tt></a> or
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.RLock" title="multiprocessing.RLock"><tt class="xref py py-class docutils literal"><span class="pre">RLock</span></tt></a> object then that will be used to synchronize access to the
value.  If <em>lock</em> is <tt class="xref docutils literal"><span class="pre">False</span></tt> then access to the returned object will not be
automatically protected by a lock, so it will not necessarily be
“process-safe”.</p>
<p>Note that <em>lock</em> is a keyword only argument.</p>
<p>Note that an array of <a class="reference internal" href="http://docs.python.org/2/library/ctypes.html#ctypes.c_char" title="ctypes.c_char"><tt class="xref py py-data docutils literal"><span class="pre">ctypes.c_char</span></tt></a> has <em>value</em> and <em>raw</em>
attributes which allow one to use it to store and retrieve strings.</p>
</dd></dl>

<div class="section" id="module-multiprocessing.sharedctypes">
<span id="the-multiprocessing-sharedctypes-module"></span><h4>16.6.2.6.1. The <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.sharedctypes" title="multiprocessing.sharedctypes: Allocate ctypes objects from shared memory."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing.sharedctypes</span></tt></a> module<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.sharedctypes" title="Permalink to this headline">¶</a></h4>
<p>The <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.sharedctypes" title="multiprocessing.sharedctypes: Allocate ctypes objects from shared memory."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing.sharedctypes</span></tt></a> module provides functions for allocating
<a class="reference internal" href="http://docs.python.org/2/library/ctypes.html#module-ctypes" title="ctypes: A foreign function library for Python."><tt class="xref py py-mod docutils literal"><span class="pre">ctypes</span></tt></a> objects from shared memory which can be inherited by child
processes.</p>
<div class="admonition note">
<p class="first admonition-title">Note</p>
<p class="last">Although it is possible to store a pointer in shared memory remember that
this will refer to a location in the address space of a specific process.
However, the pointer is quite likely to be invalid in the context of a second
process and trying to dereference the pointer from the second process may
cause a crash.</p>
</div>
<dl class="function">
<dt id="multiprocessing.sharedctypes.RawArray">
<tt class="descclassname">multiprocessing.sharedctypes.</tt><tt class="descname">RawArray</tt><big>(</big><em>typecode_or_type</em>, <em>size_or_initializer</em><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.sharedctypes.RawArray" title="Permalink to this definition">¶</a></dt>
<dd><p>Return a ctypes array allocated from shared memory.</p>
<p><em>typecode_or_type</em> determines the type of the elements of the returned array:
it is either a ctypes type or a one character typecode of the kind used by
the <a class="reference internal" href="http://docs.python.org/2/library/array.html#module-array" title="array: Space efficient arrays of uniformly typed numeric values."><tt class="xref py py-mod docutils literal"><span class="pre">array</span></tt></a> module.  If <em>size_or_initializer</em> is an integer then it
determines the length of the array, and the array will be initially zeroed.
Otherwise <em>size_or_initializer</em> is a sequence which is used to initialize the
array and whose length determines the length of the array.</p>
<p>Note that setting and getting an element is potentially non-atomic – use
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.sharedctypes.Array" title="multiprocessing.sharedctypes.Array"><tt class="xref py py-func docutils literal"><span class="pre">Array()</span></tt></a> instead to make sure that access is automatically synchronized
using a lock.</p>
</dd></dl>

<dl class="function">
<dt id="multiprocessing.sharedctypes.RawValue">
<tt class="descclassname">multiprocessing.sharedctypes.</tt><tt class="descname">RawValue</tt><big>(</big><em>typecode_or_type</em>, <em>*args</em><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.sharedctypes.RawValue" title="Permalink to this definition">¶</a></dt>
<dd><p>Return a ctypes object allocated from shared memory.</p>
<p><em>typecode_or_type</em> determines the type of the returned object: it is either a
ctypes type or a one character typecode of the kind used by the <a class="reference internal" href="http://docs.python.org/2/library/array.html#module-array" title="array: Space efficient arrays of uniformly typed numeric values."><tt class="xref py py-mod docutils literal"><span class="pre">array</span></tt></a>
module.  <em>*args</em> is passed on to the constructor for the type.</p>
<p>Note that setting and getting the value is potentially non-atomic – use
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.sharedctypes.Value" title="multiprocessing.sharedctypes.Value"><tt class="xref py py-func docutils literal"><span class="pre">Value()</span></tt></a> instead to make sure that access is automatically synchronized
using a lock.</p>
<p>Note that an array of <a class="reference internal" href="http://docs.python.org/2/library/ctypes.html#ctypes.c_char" title="ctypes.c_char"><tt class="xref py py-data docutils literal"><span class="pre">ctypes.c_char</span></tt></a> has <tt class="docutils literal"><span class="pre">value</span></tt> and <tt class="docutils literal"><span class="pre">raw</span></tt>
attributes which allow one to use it to store and retrieve strings – see
documentation for <a class="reference internal" href="http://docs.python.org/2/library/ctypes.html#module-ctypes" title="ctypes: A foreign function library for Python."><tt class="xref py py-mod docutils literal"><span class="pre">ctypes</span></tt></a>.</p>
</dd></dl>

<dl class="function">
<dt id="multiprocessing.sharedctypes.Array">
<tt class="descclassname">multiprocessing.sharedctypes.</tt><tt class="descname">Array</tt><big>(</big><em>typecode_or_type</em>, <em>size_or_initializer</em>, <em>*args</em><span class="optional">[</span>, <em>lock</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.sharedctypes.Array" title="Permalink to this definition">¶</a></dt>
<dd><p>The same as <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.sharedctypes.RawArray" title="multiprocessing.sharedctypes.RawArray"><tt class="xref py py-func docutils literal"><span class="pre">RawArray()</span></tt></a> except that depending on the value of <em>lock</em> a
process-safe synchronization wrapper may be returned instead of a raw ctypes
array.</p>
<p>If <em>lock</em> is <tt class="xref docutils literal"><span class="pre">True</span></tt> (the default) then a new lock object is created to
synchronize access to the value.  If <em>lock</em> is a
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Lock" title="multiprocessing.Lock"><tt class="xref py py-class docutils literal"><span class="pre">Lock</span></tt></a> or <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.RLock" title="multiprocessing.RLock"><tt class="xref py py-class docutils literal"><span class="pre">RLock</span></tt></a> object
then that will be used to synchronize access to the
value.  If <em>lock</em> is <tt class="xref docutils literal"><span class="pre">False</span></tt> then access to the returned object will not be
automatically protected by a lock, so it will not necessarily be
“process-safe”.</p>
<p>Note that <em>lock</em> is a keyword-only argument.</p>
</dd></dl>

<dl class="function">
<dt id="multiprocessing.sharedctypes.Value">
<tt class="descclassname">multiprocessing.sharedctypes.</tt><tt class="descname">Value</tt><big>(</big><em>typecode_or_type</em>, <em>*args</em><span class="optional">[</span>, <em>lock</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.sharedctypes.Value" title="Permalink to this definition">¶</a></dt>
<dd><p>The same as <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.sharedctypes.RawValue" title="multiprocessing.sharedctypes.RawValue"><tt class="xref py py-func docutils literal"><span class="pre">RawValue()</span></tt></a> except that depending on the value of <em>lock</em> a
process-safe synchronization wrapper may be returned instead of a raw ctypes
object.</p>
<p>If <em>lock</em> is <tt class="xref docutils literal"><span class="pre">True</span></tt> (the default) then a new lock object is created to
synchronize access to the value.  If <em>lock</em> is a <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Lock" title="multiprocessing.Lock"><tt class="xref py py-class docutils literal"><span class="pre">Lock</span></tt></a> or
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.RLock" title="multiprocessing.RLock"><tt class="xref py py-class docutils literal"><span class="pre">RLock</span></tt></a> object then that will be used to synchronize access to the
value.  If <em>lock</em> is <tt class="xref docutils literal"><span class="pre">False</span></tt> then access to the returned object will not be
automatically protected by a lock, so it will not necessarily be
“process-safe”.</p>
<p>Note that <em>lock</em> is a keyword-only argument.</p>
</dd></dl>

<dl class="function">
<dt id="multiprocessing.sharedctypes.copy">
<tt class="descclassname">multiprocessing.sharedctypes.</tt><tt class="descname">copy</tt><big>(</big><em>obj</em><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.sharedctypes.copy" title="Permalink to this definition">¶</a></dt>
<dd><p>Return a ctypes object allocated from shared memory which is a copy of the
ctypes object <em>obj</em>.</p>
</dd></dl>

<dl class="function">
<dt id="multiprocessing.sharedctypes.synchronized">
<tt class="descclassname">multiprocessing.sharedctypes.</tt><tt class="descname">synchronized</tt><big>(</big><em>obj</em><span class="optional">[</span>, <em>lock</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.sharedctypes.synchronized" title="Permalink to this definition">¶</a></dt>
<dd><p>Return a process-safe wrapper object for a ctypes object which uses <em>lock</em> to
synchronize access.  If <em>lock</em> is <tt class="xref docutils literal"><span class="pre">None</span></tt> (the default) then a
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.RLock" title="multiprocessing.RLock"><tt class="xref py py-class docutils literal"><span class="pre">multiprocessing.RLock</span></tt></a> object is created automatically.</p>
<p>A synchronized wrapper will have two methods in addition to those of the
object it wraps: <tt class="xref py py-meth docutils literal"><span class="pre">get_obj()</span></tt> returns the wrapped object and
<tt class="xref py py-meth docutils literal"><span class="pre">get_lock()</span></tt> returns the lock object used for synchronization.</p>
<p>Note that accessing the ctypes object through the wrapper can be a lot slower
than accessing the raw ctypes object.</p>
</dd></dl>

<p>The table below compares the syntax for creating shared ctypes objects from
shared memory with the normal ctypes syntax.  (In the table <tt class="docutils literal"><span class="pre">MyStruct</span></tt> is some
subclass of <a class="reference internal" href="http://docs.python.org/2/library/ctypes.html#ctypes.Structure" title="ctypes.Structure"><tt class="xref py py-class docutils literal"><span class="pre">ctypes.Structure</span></tt></a>.)</p>
<table border="1" class="docutils">
<colgroup>
<col width="27%">
<col width="36%">
<col width="37%">
</colgroup>
<thead valign="bottom">
<tr><th class="head">ctypes</th>
<th class="head">sharedctypes using type</th>
<th class="head">sharedctypes using typecode</th>
</tr>
</thead>
<tbody valign="top">
<tr><td>c_double(2.4)</td>
<td>RawValue(c_double, 2.4)</td>
<td>RawValue(‘d’, 2.4)</td>
</tr>
<tr><td>MyStruct(4, 6)</td>
<td>RawValue(MyStruct, 4, 6)</td>
<td>&nbsp;</td>
</tr>
<tr><td>(c_short * 7)()</td>
<td>RawArray(c_short, 7)</td>
<td>RawArray(‘h’, 7)</td>
</tr>
<tr><td>(c_int * 3)(9, 2, 8)</td>
<td>RawArray(c_int, (9, 2, 8))</td>
<td>RawArray(‘i’, (9, 2, 8))</td>
</tr>
</tbody>
</table>
<p>Below is an example where a number of ctypes objects are modified by a child
process:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">Lock</span>
<span class="kn">from</span> <span class="nn">multiprocessing.sharedctypes</span> <span class="kn">import</span> <span class="n">Value</span><span class="p">,</span> <span class="n">Array</span>
<span class="kn">from</span> <span class="nn">ctypes</span> <span class="kn">import</span> <span class="n">Structure</span><span class="p">,</span> <span class="n">c_double</span>

<span class="k">class</span> <span class="nc">Point</span><span class="p">(</span><span class="n">Structure</span><span class="p">):</span>
    <span class="n">_fields_</span> <span class="o">=</span> <span class="p">[(</span><span class="s">'x'</span><span class="p">,</span> <span class="n">c_double</span><span class="p">),</span> <span class="p">(</span><span class="s">'y'</span><span class="p">,</span> <span class="n">c_double</span><span class="p">)]</span>

<span class="k">def</span> <span class="nf">modify</span><span class="p">(</span><span class="n">n</span><span class="p">,</span> <span class="n">x</span><span class="p">,</span> <span class="n">s</span><span class="p">,</span> <span class="n">A</span><span class="p">):</span>
    <span class="n">n</span><span class="o">.</span><span class="n">value</span> <span class="o">**=</span> <span class="mi">2</span>
    <span class="n">x</span><span class="o">.</span><span class="n">value</span> <span class="o">**=</span> <span class="mi">2</span>
    <span class="n">s</span><span class="o">.</span><span class="n">value</span> <span class="o">=</span> <span class="n">s</span><span class="o">.</span><span class="n">value</span><span class="o">.</span><span class="n">upper</span><span class="p">()</span>
    <span class="k">for</span> <span class="n">a</span> <span class="ow">in</span> <span class="n">A</span><span class="p">:</span>
        <span class="n">a</span><span class="o">.</span><span class="n">x</span> <span class="o">**=</span> <span class="mi">2</span>
        <span class="n">a</span><span class="o">.</span><span class="n">y</span> <span class="o">**=</span> <span class="mi">2</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">lock</span> <span class="o">=</span> <span class="n">Lock</span><span class="p">()</span>

    <span class="n">n</span> <span class="o">=</span> <span class="n">Value</span><span class="p">(</span><span class="s">'i'</span><span class="p">,</span> <span class="mi">7</span><span class="p">)</span>
    <span class="n">x</span> <span class="o">=</span> <span class="n">Value</span><span class="p">(</span><span class="n">c_double</span><span class="p">,</span> <span class="mf">1.0</span><span class="o">/</span><span class="mf">3.0</span><span class="p">,</span> <span class="n">lock</span><span class="o">=</span><span class="bp">False</span><span class="p">)</span>
    <span class="n">s</span> <span class="o">=</span> <span class="n">Array</span><span class="p">(</span><span class="s">'c'</span><span class="p">,</span> <span class="s">'hello world'</span><span class="p">,</span> <span class="n">lock</span><span class="o">=</span><span class="n">lock</span><span class="p">)</span>
    <span class="n">A</span> <span class="o">=</span> <span class="n">Array</span><span class="p">(</span><span class="n">Point</span><span class="p">,</span> <span class="p">[(</span><span class="mf">1.875</span><span class="p">,</span><span class="o">-</span><span class="mf">6.25</span><span class="p">),</span> <span class="p">(</span><span class="o">-</span><span class="mf">5.75</span><span class="p">,</span><span class="mf">2.0</span><span class="p">),</span> <span class="p">(</span><span class="mf">2.375</span><span class="p">,</span><span class="mf">9.5</span><span class="p">)],</span> <span class="n">lock</span><span class="o">=</span><span class="n">lock</span><span class="p">)</span>

    <span class="n">p</span> <span class="o">=</span> <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">modify</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">n</span><span class="p">,</span> <span class="n">x</span><span class="p">,</span> <span class="n">s</span><span class="p">,</span> <span class="n">A</span><span class="p">))</span>
    <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
    <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>

    <span class="k">print</span> <span class="n">n</span><span class="o">.</span><span class="n">value</span>
    <span class="k">print</span> <span class="n">x</span><span class="o">.</span><span class="n">value</span>
    <span class="k">print</span> <span class="n">s</span><span class="o">.</span><span class="n">value</span>
    <span class="k">print</span> <span class="p">[(</span><span class="n">a</span><span class="o">.</span><span class="n">x</span><span class="p">,</span> <span class="n">a</span><span class="o">.</span><span class="n">y</span><span class="p">)</span> <span class="k">for</span> <span class="n">a</span> <span class="ow">in</span> <span class="n">A</span><span class="p">]</span>
</pre></div>
</div>
<p>The results printed are</p>
<div class="highlight-none"><div class="highlight"><pre>49
0.1111111111111111
HELLO WORLD
[(3.515625, 39.0625), (33.0625, 4.0), (5.640625, 90.25)]
</pre></div>
</div>
</div>
</div>
<div class="section" id="managers">
<span id="multiprocessing-managers"></span><h3>16.6.2.7. Managers<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#managers" title="Permalink to this headline">¶</a></h3>
<p>Managers provide a way to create data which can be shared between different
processes. A manager object controls a server process which manages <em>shared
objects</em>.  Other processes can access the shared objects by using proxies.</p>
<dl class="function">
<dt id="multiprocessing.sharedctypes.multiprocessing.Manager">
<tt class="descclassname">multiprocessing.</tt><tt class="descname">Manager</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.sharedctypes.multiprocessing.Manager" title="Permalink to this definition">¶</a></dt>
<dd><p>Returns a started <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager" title="multiprocessing.managers.SyncManager"><tt class="xref py py-class docutils literal"><span class="pre">SyncManager</span></tt></a> object which
can be used for sharing objects between processes.  The returned manager
object corresponds to a spawned child process and has methods which will
create shared objects and return corresponding proxies.</p>
</dd></dl>

<span class="target" id="module-multiprocessing.managers"></span><p>Manager processes will be shutdown as soon as they are garbage collected or
their parent process exits.  The manager classes are defined in the
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.managers" title="multiprocessing.managers: Share data between process with shared objects."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing.managers</span></tt></a> module:</p>
<dl class="class">
<dt id="multiprocessing.managers.BaseManager">
<em class="property">class </em><tt class="descclassname">multiprocessing.managers.</tt><tt class="descname">BaseManager</tt><big>(</big><span class="optional">[</span><em>address</em><span class="optional">[</span>, <em>authkey</em><span class="optional">]</span><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager" title="Permalink to this definition">¶</a></dt>
<dd><p>Create a BaseManager object.</p>
<p>Once created one should call <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager.start" title="multiprocessing.managers.BaseManager.start"><tt class="xref py py-meth docutils literal"><span class="pre">start()</span></tt></a> or <tt class="docutils literal"><span class="pre">get_server().serve_forever()</span></tt> to ensure
that the manager object refers to a started manager process.</p>
<p><em>address</em> is the address on which the manager process listens for new
connections.  If <em>address</em> is <tt class="xref docutils literal"><span class="pre">None</span></tt> then an arbitrary one is chosen.</p>
<p><em>authkey</em> is the authentication key which will be used to check the validity
of incoming connections to the server process.  If <em>authkey</em> is <tt class="xref docutils literal"><span class="pre">None</span></tt> then
<tt class="docutils literal"><span class="pre">current_process().authkey</span></tt>.  Otherwise <em>authkey</em> is used and it
must be a string.</p>
<dl class="method">
<dt id="multiprocessing.managers.BaseManager.start">
<tt class="descname">start</tt><big>(</big><span class="optional">[</span><em>initializer</em><span class="optional">[</span>, <em>initargs</em><span class="optional">]</span><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager.start" title="Permalink to this definition">¶</a></dt>
<dd><p>Start a subprocess to start the manager.  If <em>initializer</em> is not <tt class="xref docutils literal"><span class="pre">None</span></tt>
then the subprocess will call <tt class="docutils literal"><span class="pre">initializer(*initargs)</span></tt> when it starts.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.BaseManager.get_server">
<tt class="descname">get_server</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager.get_server" title="Permalink to this definition">¶</a></dt>
<dd><p>Returns a <tt class="xref py py-class docutils literal"><span class="pre">Server</span></tt> object which represents the actual server under
the control of the Manager. The <tt class="xref py py-class docutils literal"><span class="pre">Server</span></tt> object supports the
<tt class="xref py py-meth docutils literal"><span class="pre">serve_forever()</span></tt> method:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="kn">from</span> <span class="nn">multiprocessing.managers</span> <span class="kn">import</span> <span class="n">BaseManager</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">manager</span> <span class="o">=</span> <span class="n">BaseManager</span><span class="p">(</span><span class="n">address</span><span class="o">=</span><span class="p">(</span><span class="s">''</span><span class="p">,</span> <span class="mi">50000</span><span class="p">),</span> <span class="n">authkey</span><span class="o">=</span><span class="s">'abc'</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">server</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">get_server</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">server</span><span class="o">.</span><span class="n">serve_forever</span><span class="p">()</span>
</pre></div>
</div>
<p><tt class="xref py py-class docutils literal"><span class="pre">Server</span></tt> additionally has an <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager.address" title="multiprocessing.managers.BaseManager.address"><tt class="xref py py-attr docutils literal"><span class="pre">address</span></tt></a> attribute.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.BaseManager.connect">
<tt class="descname">connect</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager.connect" title="Permalink to this definition">¶</a></dt>
<dd><p>Connect a local manager object to a remote manager process:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="kn">from</span> <span class="nn">multiprocessing.managers</span> <span class="kn">import</span> <span class="n">BaseManager</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">m</span> <span class="o">=</span> <span class="n">BaseManager</span><span class="p">(</span><span class="n">address</span><span class="o">=</span><span class="p">(</span><span class="s">'127.0.0.1'</span><span class="p">,</span> <span class="mi">5000</span><span class="p">),</span> <span class="n">authkey</span><span class="o">=</span><span class="s">'abc'</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">m</span><span class="o">.</span><span class="n">connect</span><span class="p">()</span>
</pre></div>
</div>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.BaseManager.shutdown">
<tt class="descname">shutdown</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager.shutdown" title="Permalink to this definition">¶</a></dt>
<dd><p>Stop the process used by the manager.  This is only available if
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager.start" title="multiprocessing.managers.BaseManager.start"><tt class="xref py py-meth docutils literal"><span class="pre">start()</span></tt></a> has been used to start the server process.</p>
<p>This can be called multiple times.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.BaseManager.register">
<tt class="descname">register</tt><big>(</big><em>typeid</em><span class="optional">[</span>, <em>callable</em><span class="optional">[</span>, <em>proxytype</em><span class="optional">[</span>, <em>exposed</em><span class="optional">[</span>, <em>method_to_typeid</em><span class="optional">[</span>, <em>create_method</em><span class="optional">]</span><span class="optional">]</span><span class="optional">]</span><span class="optional">]</span><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager.register" title="Permalink to this definition">¶</a></dt>
<dd><p>A classmethod which can be used for registering a type or callable with
the manager class.</p>
<p><em>typeid</em> is a “type identifier” which is used to identify a particular
type of shared object.  This must be a string.</p>
<p><em>callable</em> is a callable used for creating objects for this type
identifier.  If a manager instance will be created using the
<tt class="xref py py-meth docutils literal"><span class="pre">from_address()</span></tt> classmethod or if the <em>create_method</em> argument is
<tt class="xref docutils literal"><span class="pre">False</span></tt> then this can be left as <tt class="xref docutils literal"><span class="pre">None</span></tt>.</p>
<p><em>proxytype</em> is a subclass of <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseProxy" title="multiprocessing.managers.BaseProxy"><tt class="xref py py-class docutils literal"><span class="pre">BaseProxy</span></tt></a> which is used to create
proxies for shared objects with this <em>typeid</em>.  If <tt class="xref docutils literal"><span class="pre">None</span></tt> then a proxy
class is created automatically.</p>
<p><em>exposed</em> is used to specify a sequence of method names which proxies for
this typeid should be allowed to access using
<tt class="xref py py-meth docutils literal"><span class="pre">BaseProxy._callMethod()</span></tt>.  (If <em>exposed</em> is <tt class="xref docutils literal"><span class="pre">None</span></tt> then
<tt class="xref py py-attr docutils literal"><span class="pre">proxytype._exposed_</span></tt> is used instead if it exists.)  In the case
where no exposed list is specified, all “public methods” of the shared
object will be accessible.  (Here a “public method” means any attribute
which has a <a class="reference internal" href="http://docs.python.org/2/reference/datamodel.html#object.__call__" title="object.__call__"><tt class="xref py py-meth docutils literal"><span class="pre">__call__()</span></tt></a> method and whose name does not begin
with <tt class="docutils literal"><span class="pre">'_'</span></tt>.)</p>
<p><em>method_to_typeid</em> is a mapping used to specify the return type of those
exposed methods which should return a proxy.  It maps method names to
typeid strings.  (If <em>method_to_typeid</em> is <tt class="xref docutils literal"><span class="pre">None</span></tt> then
<tt class="xref py py-attr docutils literal"><span class="pre">proxytype._method_to_typeid_</span></tt> is used instead if it exists.)  If a
method’s name is not a key of this mapping or if the mapping is <tt class="xref docutils literal"><span class="pre">None</span></tt>
then the object returned by the method will be copied by value.</p>
<p><em>create_method</em> determines whether a method should be created with name
<em>typeid</em> which can be used to tell the server process to create a new
shared object and return a proxy for it.  By default it is <tt class="xref docutils literal"><span class="pre">True</span></tt>.</p>
</dd></dl>

<p><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager" title="multiprocessing.managers.BaseManager"><tt class="xref py py-class docutils literal"><span class="pre">BaseManager</span></tt></a> instances also have one read-only property:</p>
<dl class="attribute">
<dt id="multiprocessing.managers.BaseManager.address">
<tt class="descname">address</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager.address" title="Permalink to this definition">¶</a></dt>
<dd><p>The address used by the manager.</p>
</dd></dl>

</dd></dl>

<dl class="class">
<dt id="multiprocessing.managers.SyncManager">
<em class="property">class </em><tt class="descclassname">multiprocessing.managers.</tt><tt class="descname">SyncManager</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager" title="Permalink to this definition">¶</a></dt>
<dd><p>A subclass of <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager" title="multiprocessing.managers.BaseManager"><tt class="xref py py-class docutils literal"><span class="pre">BaseManager</span></tt></a> which can be used for the synchronization
of processes.  Objects of this type are returned by
<tt class="xref py py-func docutils literal"><span class="pre">multiprocessing.Manager()</span></tt>.</p>
<p>It also supports creation of shared lists and dictionaries.</p>
<dl class="method">
<dt id="multiprocessing.managers.SyncManager.BoundedSemaphore">
<tt class="descname">BoundedSemaphore</tt><big>(</big><span class="optional">[</span><em>value</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager.BoundedSemaphore" title="Permalink to this definition">¶</a></dt>
<dd><p>Create a shared <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.BoundedSemaphore" title="threading.BoundedSemaphore"><tt class="xref py py-class docutils literal"><span class="pre">threading.BoundedSemaphore</span></tt></a> object and return a
proxy for it.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.SyncManager.Condition">
<tt class="descname">Condition</tt><big>(</big><span class="optional">[</span><em>lock</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager.Condition" title="Permalink to this definition">¶</a></dt>
<dd><p>Create a shared <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Condition" title="threading.Condition"><tt class="xref py py-class docutils literal"><span class="pre">threading.Condition</span></tt></a> object and return a proxy for
it.</p>
<p>If <em>lock</em> is supplied then it should be a proxy for a
<a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Lock" title="threading.Lock"><tt class="xref py py-class docutils literal"><span class="pre">threading.Lock</span></tt></a> or <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.RLock" title="threading.RLock"><tt class="xref py py-class docutils literal"><span class="pre">threading.RLock</span></tt></a> object.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.SyncManager.Event">
<tt class="descname">Event</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager.Event" title="Permalink to this definition">¶</a></dt>
<dd><p>Create a shared <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Event" title="threading.Event"><tt class="xref py py-class docutils literal"><span class="pre">threading.Event</span></tt></a> object and return a proxy for it.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.SyncManager.Lock">
<tt class="descname">Lock</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager.Lock" title="Permalink to this definition">¶</a></dt>
<dd><p>Create a shared <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Lock" title="threading.Lock"><tt class="xref py py-class docutils literal"><span class="pre">threading.Lock</span></tt></a> object and return a proxy for it.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.SyncManager.Namespace">
<tt class="descname">Namespace</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager.Namespace" title="Permalink to this definition">¶</a></dt>
<dd><p>Create a shared <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager.Namespace" title="multiprocessing.managers.SyncManager.Namespace"><tt class="xref py py-class docutils literal"><span class="pre">Namespace</span></tt></a> object and return a proxy for it.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.SyncManager.Queue">
<tt class="descname">Queue</tt><big>(</big><span class="optional">[</span><em>maxsize</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager.Queue" title="Permalink to this definition">¶</a></dt>
<dd><p>Create a shared <a class="reference internal" href="http://docs.python.org/2/library/queue.html#Queue.Queue" title="Queue.Queue"><tt class="xref py py-class docutils literal"><span class="pre">Queue.Queue</span></tt></a> object and return a proxy for it.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.SyncManager.RLock">
<tt class="descname">RLock</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager.RLock" title="Permalink to this definition">¶</a></dt>
<dd><p>Create a shared <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.RLock" title="threading.RLock"><tt class="xref py py-class docutils literal"><span class="pre">threading.RLock</span></tt></a> object and return a proxy for it.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.SyncManager.Semaphore">
<tt class="descname">Semaphore</tt><big>(</big><span class="optional">[</span><em>value</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager.Semaphore" title="Permalink to this definition">¶</a></dt>
<dd><p>Create a shared <a class="reference internal" href="http://docs.python.org/2/library/threading.html#threading.Semaphore" title="threading.Semaphore"><tt class="xref py py-class docutils literal"><span class="pre">threading.Semaphore</span></tt></a> object and return a proxy for
it.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.SyncManager.Array">
<tt class="descname">Array</tt><big>(</big><em>typecode</em>, <em>sequence</em><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager.Array" title="Permalink to this definition">¶</a></dt>
<dd><p>Create an array and return a proxy for it.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.SyncManager.Value">
<tt class="descname">Value</tt><big>(</big><em>typecode</em>, <em>value</em><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager.Value" title="Permalink to this definition">¶</a></dt>
<dd><p>Create an object with a writable <tt class="docutils literal"><span class="pre">value</span></tt> attribute and return a proxy
for it.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.SyncManager.dict">
<tt class="descname">dict</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager.dict" title="Permalink to this definition">¶</a></dt>
<dt>
<tt class="descname">dict</tt><big>(</big><em>mapping</em><big>)</big></dt>
<dt>
<tt class="descname">dict</tt><big>(</big><em>sequence</em><big>)</big></dt>
<dd><p>Create a shared <tt class="docutils literal"><span class="pre">dict</span></tt> object and return a proxy for it.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.SyncManager.list">
<tt class="descname">list</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.SyncManager.list" title="Permalink to this definition">¶</a></dt>
<dt>
<tt class="descname">list</tt><big>(</big><em>sequence</em><big>)</big></dt>
<dd><p>Create a shared <tt class="docutils literal"><span class="pre">list</span></tt> object and return a proxy for it.</p>
</dd></dl>

<div class="admonition note">
<p class="first admonition-title">Note</p>
<p>Modifications to mutable values or items in dict and list proxies will not
be propagated through the manager, because the proxy has no way of knowing
when its values or items are modified.  To modify such an item, you can
re-assign the modified object to the container proxy:</p>
<div class="last highlight-python" style="position: relative;"><div class="highlight"><pre><span class="c"># create a list proxy and append a mutable object (a dictionary)</span>
<span class="n">lproxy</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">list</span><span class="p">()</span>
<span class="n">lproxy</span><span class="o">.</span><span class="n">append</span><span class="p">({})</span>
<span class="c"># now mutate the dictionary</span>
<span class="n">d</span> <span class="o">=</span> <span class="n">lproxy</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span>
<span class="n">d</span><span class="p">[</span><span class="s">'a'</span><span class="p">]</span> <span class="o">=</span> <span class="mi">1</span>
<span class="n">d</span><span class="p">[</span><span class="s">'b'</span><span class="p">]</span> <span class="o">=</span> <span class="mi">2</span>
<span class="c"># at this point, the changes to d are not yet synced, but by</span>
<span class="c"># reassigning the dictionary, the proxy is notified of the change</span>
<span class="n">lproxy</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">=</span> <span class="n">d</span>
</pre></div>
</div>
</div>
</dd></dl>

<div class="section" id="namespace-objects">
<h4>16.6.2.7.1. Namespace objects<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#namespace-objects" title="Permalink to this headline">¶</a></h4>
<p>A namespace object has no public methods, but does have writable attributes.
Its representation shows the values of its attributes.</p>
<p>However, when using a proxy for a namespace object, an attribute beginning with
<tt class="docutils literal"><span class="pre">'_'</span></tt> will be an attribute of the proxy and not an attribute of the referent:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="n">manager</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Manager</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">Global</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">Namespace</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">Global</span><span class="o">.</span><span class="n">x</span> <span class="o">=</span> <span class="mi">10</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">Global</span><span class="o">.</span><span class="n">y</span> <span class="o">=</span> <span class="s">'hello'</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">Global</span><span class="o">.</span><span class="n">_z</span> <span class="o">=</span> <span class="mf">12.3</span>    <span class="c"># this is an attribute of the proxy</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">print</span> <span class="n">Global</span>
<span class="go">Namespace(x=10, y='hello')</span>
</pre></div>
</div>
</div>
<div class="section" id="customized-managers">
<h4>16.6.2.7.2. Customized managers<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#customized-managers" title="Permalink to this headline">¶</a></h4>
<p>To create one’s own manager, one creates a subclass of <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager" title="multiprocessing.managers.BaseManager"><tt class="xref py py-class docutils literal"><span class="pre">BaseManager</span></tt></a> and
uses the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager.register" title="multiprocessing.managers.BaseManager.register"><tt class="xref py py-meth docutils literal"><span class="pre">register()</span></tt></a> classmethod to register new types or
callables with the manager class.  For example:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing.managers</span> <span class="kn">import</span> <span class="n">BaseManager</span>

<span class="k">class</span> <span class="nc">MathsClass</span><span class="p">(</span><span class="nb">object</span><span class="p">):</span>
    <span class="k">def</span> <span class="nf">add</span><span class="p">(</span><span class="bp">self</span><span class="p">,</span> <span class="n">x</span><span class="p">,</span> <span class="n">y</span><span class="p">):</span>
        <span class="k">return</span> <span class="n">x</span> <span class="o">+</span> <span class="n">y</span>
    <span class="k">def</span> <span class="nf">mul</span><span class="p">(</span><span class="bp">self</span><span class="p">,</span> <span class="n">x</span><span class="p">,</span> <span class="n">y</span><span class="p">):</span>
        <span class="k">return</span> <span class="n">x</span> <span class="o">*</span> <span class="n">y</span>

<span class="k">class</span> <span class="nc">MyManager</span><span class="p">(</span><span class="n">BaseManager</span><span class="p">):</span>
    <span class="k">pass</span>

<span class="n">MyManager</span><span class="o">.</span><span class="n">register</span><span class="p">(</span><span class="s">'Maths'</span><span class="p">,</span> <span class="n">MathsClass</span><span class="p">)</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">manager</span> <span class="o">=</span> <span class="n">MyManager</span><span class="p">()</span>
    <span class="n">manager</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
    <span class="n">maths</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">Maths</span><span class="p">()</span>
    <span class="k">print</span> <span class="n">maths</span><span class="o">.</span><span class="n">add</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span> <span class="mi">3</span><span class="p">)</span>         <span class="c"># prints 7</span>
    <span class="k">print</span> <span class="n">maths</span><span class="o">.</span><span class="n">mul</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span> <span class="mi">8</span><span class="p">)</span>         <span class="c"># prints 56</span>
</pre></div>
</div>
</div>
<div class="section" id="using-a-remote-manager">
<h4>16.6.2.7.3. Using a remote manager<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#using-a-remote-manager" title="Permalink to this headline">¶</a></h4>
<p>It is possible to run a manager server on one machine and have clients use it
from other machines (assuming that the firewalls involved allow it).</p>
<p>Running the following commands creates a server for a single shared queue which
remote clients can access:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="kn">from</span> <span class="nn">multiprocessing.managers</span> <span class="kn">import</span> <span class="n">BaseManager</span>
<span class="gp">&gt;&gt;&gt; </span><span class="kn">import</span> <span class="nn">Queue</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">queue</span> <span class="o">=</span> <span class="n">Queue</span><span class="o">.</span><span class="n">Queue</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">class</span> <span class="nc">QueueManager</span><span class="p">(</span><span class="n">BaseManager</span><span class="p">):</span> <span class="k">pass</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">QueueManager</span><span class="o">.</span><span class="n">register</span><span class="p">(</span><span class="s">'get_queue'</span><span class="p">,</span> <span class="nb">callable</span><span class="o">=</span><span class="k">lambda</span><span class="p">:</span><span class="n">queue</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">m</span> <span class="o">=</span> <span class="n">QueueManager</span><span class="p">(</span><span class="n">address</span><span class="o">=</span><span class="p">(</span><span class="s">''</span><span class="p">,</span> <span class="mi">50000</span><span class="p">),</span> <span class="n">authkey</span><span class="o">=</span><span class="s">'abracadabra'</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">s</span> <span class="o">=</span> <span class="n">m</span><span class="o">.</span><span class="n">get_server</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">s</span><span class="o">.</span><span class="n">serve_forever</span><span class="p">()</span>
</pre></div>
</div>
<p>One client can access the server as follows:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="kn">from</span> <span class="nn">multiprocessing.managers</span> <span class="kn">import</span> <span class="n">BaseManager</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">class</span> <span class="nc">QueueManager</span><span class="p">(</span><span class="n">BaseManager</span><span class="p">):</span> <span class="k">pass</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">QueueManager</span><span class="o">.</span><span class="n">register</span><span class="p">(</span><span class="s">'get_queue'</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">m</span> <span class="o">=</span> <span class="n">QueueManager</span><span class="p">(</span><span class="n">address</span><span class="o">=</span><span class="p">(</span><span class="s">'foo.bar.org'</span><span class="p">,</span> <span class="mi">50000</span><span class="p">),</span> <span class="n">authkey</span><span class="o">=</span><span class="s">'abracadabra'</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">m</span><span class="o">.</span><span class="n">connect</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">queue</span> <span class="o">=</span> <span class="n">m</span><span class="o">.</span><span class="n">get_queue</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">queue</span><span class="o">.</span><span class="n">put</span><span class="p">(</span><span class="s">'hello'</span><span class="p">)</span>
</pre></div>
</div>
<p>Another client can also use it:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="kn">from</span> <span class="nn">multiprocessing.managers</span> <span class="kn">import</span> <span class="n">BaseManager</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">class</span> <span class="nc">QueueManager</span><span class="p">(</span><span class="n">BaseManager</span><span class="p">):</span> <span class="k">pass</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">QueueManager</span><span class="o">.</span><span class="n">register</span><span class="p">(</span><span class="s">'get_queue'</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">m</span> <span class="o">=</span> <span class="n">QueueManager</span><span class="p">(</span><span class="n">address</span><span class="o">=</span><span class="p">(</span><span class="s">'foo.bar.org'</span><span class="p">,</span> <span class="mi">50000</span><span class="p">),</span> <span class="n">authkey</span><span class="o">=</span><span class="s">'abracadabra'</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">m</span><span class="o">.</span><span class="n">connect</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">queue</span> <span class="o">=</span> <span class="n">m</span><span class="o">.</span><span class="n">get_queue</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">queue</span><span class="o">.</span><span class="n">get</span><span class="p">()</span>
<span class="go">'hello'</span>
</pre></div>
</div>
<p>Local processes can also access that queue, using the code from above on the
client to access it remotely:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">Queue</span>
<span class="gp">&gt;&gt;&gt; </span><span class="kn">from</span> <span class="nn">multiprocessing.managers</span> <span class="kn">import</span> <span class="n">BaseManager</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">class</span> <span class="nc">Worker</span><span class="p">(</span><span class="n">Process</span><span class="p">):</span>
<span class="gp">... </span>    <span class="k">def</span> <span class="nf">__init__</span><span class="p">(</span><span class="bp">self</span><span class="p">,</span> <span class="n">q</span><span class="p">):</span>
<span class="gp">... </span>        <span class="bp">self</span><span class="o">.</span><span class="n">q</span> <span class="o">=</span> <span class="n">q</span>
<span class="gp">... </span>        <span class="nb">super</span><span class="p">(</span><span class="n">Worker</span><span class="p">,</span> <span class="bp">self</span><span class="p">)</span><span class="o">.</span><span class="n">__init__</span><span class="p">()</span>
<span class="gp">... </span>    <span class="k">def</span> <span class="nf">run</span><span class="p">(</span><span class="bp">self</span><span class="p">):</span>
<span class="gp">... </span>        <span class="bp">self</span><span class="o">.</span><span class="n">q</span><span class="o">.</span><span class="n">put</span><span class="p">(</span><span class="s">'local hello'</span><span class="p">)</span>
<span class="gp">...</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">queue</span> <span class="o">=</span> <span class="n">Queue</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">w</span> <span class="o">=</span> <span class="n">Worker</span><span class="p">(</span><span class="n">queue</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">w</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">class</span> <span class="nc">QueueManager</span><span class="p">(</span><span class="n">BaseManager</span><span class="p">):</span> <span class="k">pass</span>
<span class="gp">...</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">QueueManager</span><span class="o">.</span><span class="n">register</span><span class="p">(</span><span class="s">'get_queue'</span><span class="p">,</span> <span class="nb">callable</span><span class="o">=</span><span class="k">lambda</span><span class="p">:</span> <span class="n">queue</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">m</span> <span class="o">=</span> <span class="n">QueueManager</span><span class="p">(</span><span class="n">address</span><span class="o">=</span><span class="p">(</span><span class="s">''</span><span class="p">,</span> <span class="mi">50000</span><span class="p">),</span> <span class="n">authkey</span><span class="o">=</span><span class="s">'abracadabra'</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">s</span> <span class="o">=</span> <span class="n">m</span><span class="o">.</span><span class="n">get_server</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">s</span><span class="o">.</span><span class="n">serve_forever</span><span class="p">()</span>
</pre></div>
</div>
</div>
</div>
<div class="section" id="proxy-objects">
<h3>16.6.2.8. Proxy Objects<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#proxy-objects" title="Permalink to this headline">¶</a></h3>
<p>A proxy is an object which <em>refers</em> to a shared object which lives (presumably)
in a different process.  The shared object is said to be the <em>referent</em> of the
proxy.  Multiple proxy objects may have the same referent.</p>
<p>A proxy object has methods which invoke corresponding methods of its referent
(although not every method of the referent will necessarily be available through
the proxy).  A proxy can usually be used in most of the same ways that its
referent can:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Manager</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">manager</span> <span class="o">=</span> <span class="n">Manager</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">l</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">list</span><span class="p">([</span><span class="n">i</span><span class="o">*</span><span class="n">i</span> <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">)])</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">print</span> <span class="n">l</span>
<span class="go">[0, 1, 4, 9, 16, 25, 36, 49, 64, 81]</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">print</span> <span class="nb">repr</span><span class="p">(</span><span class="n">l</span><span class="p">)</span>
<span class="go">&lt;ListProxy object, typeid 'list' at 0x...&gt;</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">l</span><span class="p">[</span><span class="mi">4</span><span class="p">]</span>
<span class="go">16</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">l</span><span class="p">[</span><span class="mi">2</span><span class="p">:</span><span class="mi">5</span><span class="p">]</span>
<span class="go">[4, 9, 16]</span>
</pre></div>
</div>
<p>Notice that applying <a class="reference internal" href="http://docs.python.org/2/library/functions.html#str" title="str"><tt class="xref py py-func docutils literal"><span class="pre">str()</span></tt></a> to a proxy will return the representation of
the referent, whereas applying <a class="reference internal" href="http://docs.python.org/2/library/repr.html#module-repr" title="repr: Alternate repr() implementation with size limits."><tt class="xref py py-func docutils literal"><span class="pre">repr()</span></tt></a> will return the representation of
the proxy.</p>
<p>An important feature of proxy objects is that they are picklable so they can be
passed between processes.  Note, however, that if a proxy is sent to the
corresponding manager’s process then unpickling it will produce the referent
itself.  This means, for example, that one shared object can contain a second:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="n">a</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">list</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">b</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">list</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">a</span><span class="o">.</span><span class="n">append</span><span class="p">(</span><span class="n">b</span><span class="p">)</span>         <span class="c"># referent of a now contains referent of b</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">print</span> <span class="n">a</span><span class="p">,</span> <span class="n">b</span>
<span class="go">[[]] []</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">b</span><span class="o">.</span><span class="n">append</span><span class="p">(</span><span class="s">'hello'</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">print</span> <span class="n">a</span><span class="p">,</span> <span class="n">b</span>
<span class="go">[['hello']] ['hello']</span>
</pre></div>
</div>
<div class="admonition note">
<p class="first admonition-title">Note</p>
<p>The proxy types in <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> do nothing to support comparisons
by value.  So, for instance, we have:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="n">manager</span><span class="o">.</span><span class="n">list</span><span class="p">([</span><span class="mi">1</span><span class="p">,</span><span class="mi">2</span><span class="p">,</span><span class="mi">3</span><span class="p">])</span> <span class="o">==</span> <span class="p">[</span><span class="mi">1</span><span class="p">,</span><span class="mi">2</span><span class="p">,</span><span class="mi">3</span><span class="p">]</span>
<span class="go">False</span>
</pre></div>
</div>
<p class="last">One should just use a copy of the referent instead when making comparisons.</p>
</div>
<dl class="class">
<dt id="multiprocessing.managers.BaseProxy">
<em class="property">class </em><tt class="descclassname">multiprocessing.managers.</tt><tt class="descname">BaseProxy</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseProxy" title="Permalink to this definition">¶</a></dt>
<dd><p>Proxy objects are instances of subclasses of <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseProxy" title="multiprocessing.managers.BaseProxy"><tt class="xref py py-class docutils literal"><span class="pre">BaseProxy</span></tt></a>.</p>
<dl class="method">
<dt id="multiprocessing.managers.BaseProxy._callmethod">
<tt class="descname">_callmethod</tt><big>(</big><em>methodname</em><span class="optional">[</span>, <em>args</em><span class="optional">[</span>, <em>kwds</em><span class="optional">]</span><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseProxy._callmethod" title="Permalink to this definition">¶</a></dt>
<dd><p>Call and return the result of a method of the proxy’s referent.</p>
<p>If <tt class="docutils literal"><span class="pre">proxy</span></tt> is a proxy whose referent is <tt class="docutils literal"><span class="pre">obj</span></tt> then the expression</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="n">proxy</span><span class="o">.</span><span class="n">_callmethod</span><span class="p">(</span><span class="n">methodname</span><span class="p">,</span> <span class="n">args</span><span class="p">,</span> <span class="n">kwds</span><span class="p">)</span>
</pre></div>
</div>
<p>will evaluate the expression</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="nb">getattr</span><span class="p">(</span><span class="n">obj</span><span class="p">,</span> <span class="n">methodname</span><span class="p">)(</span><span class="o">*</span><span class="n">args</span><span class="p">,</span> <span class="o">**</span><span class="n">kwds</span><span class="p">)</span>
</pre></div>
</div>
<p>in the manager’s process.</p>
<p>The returned value will be a copy of the result of the call or a proxy to
a new shared object – see documentation for the <em>method_to_typeid</em>
argument of <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseManager.register" title="multiprocessing.managers.BaseManager.register"><tt class="xref py py-meth docutils literal"><span class="pre">BaseManager.register()</span></tt></a>.</p>
<p>If an exception is raised by the call, then is re-raised by
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseProxy._callmethod" title="multiprocessing.managers.BaseProxy._callmethod"><tt class="xref py py-meth docutils literal"><span class="pre">_callmethod()</span></tt></a>.  If some other exception is raised in the manager’s
process then this is converted into a <tt class="xref py py-exc docutils literal"><span class="pre">RemoteError</span></tt> exception and is
raised by <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseProxy._callmethod" title="multiprocessing.managers.BaseProxy._callmethod"><tt class="xref py py-meth docutils literal"><span class="pre">_callmethod()</span></tt></a>.</p>
<p>Note in particular that an exception will be raised if <em>methodname</em> has
not been <em>exposed</em></p>
<p>An example of the usage of <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseProxy._callmethod" title="multiprocessing.managers.BaseProxy._callmethod"><tt class="xref py py-meth docutils literal"><span class="pre">_callmethod()</span></tt></a>:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="n">l</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">list</span><span class="p">(</span><span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">))</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">l</span><span class="o">.</span><span class="n">_callmethod</span><span class="p">(</span><span class="s">'__len__'</span><span class="p">)</span>
<span class="go">10</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">l</span><span class="o">.</span><span class="n">_callmethod</span><span class="p">(</span><span class="s">'__getslice__'</span><span class="p">,</span> <span class="p">(</span><span class="mi">2</span><span class="p">,</span> <span class="mi">7</span><span class="p">))</span>   <span class="c"># equiv to `l[2:7]`</span>
<span class="go">[2, 3, 4, 5, 6]</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">l</span><span class="o">.</span><span class="n">_callmethod</span><span class="p">(</span><span class="s">'__getitem__'</span><span class="p">,</span> <span class="p">(</span><span class="mi">20</span><span class="p">,))</span>     <span class="c"># equiv to `l[20]`</span>
<span class="gt">Traceback (most recent call last):</span>
<span class="c">...</span>
<span class="nc">IndexError</span><span>: </span><span class="n-Identifier">list index out of range</span>
</pre></div>
</div>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.BaseProxy._getvalue">
<tt class="descname">_getvalue</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseProxy._getvalue" title="Permalink to this definition">¶</a></dt>
<dd><p>Return a copy of the referent.</p>
<p>If the referent is unpicklable then this will raise an exception.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.BaseProxy.__repr__">
<tt class="descname">__repr__</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseProxy.__repr__" title="Permalink to this definition">¶</a></dt>
<dd><p>Return a representation of the proxy object.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.managers.BaseProxy.__str__">
<tt class="descname">__str__</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.managers.BaseProxy.__str__" title="Permalink to this definition">¶</a></dt>
<dd><p>Return the representation of the referent.</p>
</dd></dl>

</dd></dl>

<div class="section" id="cleanup">
<h4>16.6.2.8.1. Cleanup<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#cleanup" title="Permalink to this headline">¶</a></h4>
<p>A proxy object uses a weakref callback so that when it gets garbage collected it
deregisters itself from the manager which owns its referent.</p>
<p>A shared object gets deleted from the manager process when there are no longer
any proxies referring to it.</p>
</div>
</div>
<div class="section" id="module-multiprocessing.pool">
<span id="process-pools"></span><h3>16.6.2.9. Process Pools<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.pool" title="Permalink to this headline">¶</a></h3>
<p>One can create a pool of processes which will carry out tasks submitted to it
with the <tt class="xref py py-class docutils literal"><span class="pre">Pool</span></tt> class.</p>
<dl class="class">
<dt id="multiprocessing.pool.multiprocessing.Pool">
<em class="property">class </em><tt class="descclassname">multiprocessing.</tt><tt class="descname">Pool</tt><big>(</big><span class="optional">[</span><em>processes</em><span class="optional">[</span>, <em>initializer</em><span class="optional">[</span>, <em>initargs</em><span class="optional">[</span>, <em>maxtasksperchild</em><span class="optional">]</span><span class="optional">]</span><span class="optional">]</span><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool" title="Permalink to this definition">¶</a></dt>
<dd><p>A process pool object which controls a pool of worker processes to which jobs
can be submitted.  It supports asynchronous results with timeouts and
callbacks and has a parallel map implementation.</p>
<p><em>processes</em> is the number of worker processes to use.  If <em>processes</em> is
<tt class="xref docutils literal"><span class="pre">None</span></tt> then the number returned by <tt class="xref py py-func docutils literal"><span class="pre">cpu_count()</span></tt> is used.  If
<em>initializer</em> is not <tt class="xref docutils literal"><span class="pre">None</span></tt> then each worker process will call
<tt class="docutils literal"><span class="pre">initializer(*initargs)</span></tt> when it starts.</p>
<p>Note that the methods of the pool object should only be called by
the process which created the pool.</p>
<p class="versionadded">
<span class="versionmodified">New in version 2.7: </span><em>maxtasksperchild</em> is the number of tasks a worker process can complete
before it will exit and be replaced with a fresh worker process, to enable
unused resources to be freed. The default <em>maxtasksperchild</em> is None, which
means worker processes will live as long as the pool.</p>
<div class="admonition note">
<p class="first admonition-title">Note</p>
<p class="last">Worker processes within a <tt class="xref py py-class docutils literal"><span class="pre">Pool</span></tt> typically live for the complete
duration of the Pool’s work queue. A frequent pattern found in other
systems (such as Apache, mod_wsgi, etc) to free resources held by
workers is to allow a worker within a pool to complete only a set
amount of work before being exiting, being cleaned up and a new
process spawned to replace the old one. The <em>maxtasksperchild</em>
argument to the <tt class="xref py py-class docutils literal"><span class="pre">Pool</span></tt> exposes this ability to the end user.</p>
</div>
<dl class="method">
<dt id="multiprocessing.pool.multiprocessing.Pool.apply">
<tt class="descname">apply</tt><big>(</big><em>func</em><span class="optional">[</span>, <em>args</em><span class="optional">[</span>, <em>kwds</em><span class="optional">]</span><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.apply" title="Permalink to this definition">¶</a></dt>
<dd><p>Equivalent of the <a class="reference internal" href="http://docs.python.org/2/library/functions.html#apply" title="apply"><tt class="xref py py-func docutils literal"><span class="pre">apply()</span></tt></a> built-in function.  It blocks until the
result is ready, so <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.apply_async" title="multiprocessing.pool.multiprocessing.Pool.apply_async"><tt class="xref py py-meth docutils literal"><span class="pre">apply_async()</span></tt></a> is better suited for performing
work in parallel. Additionally, <em>func</em> is only executed in one of the
workers of the pool.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.pool.multiprocessing.Pool.apply_async">
<tt class="descname">apply_async</tt><big>(</big><em>func</em><span class="optional">[</span>, <em>args</em><span class="optional">[</span>, <em>kwds</em><span class="optional">[</span>, <em>callback</em><span class="optional">]</span><span class="optional">]</span><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.apply_async" title="Permalink to this definition">¶</a></dt>
<dd><p>A variant of the <a class="reference internal" href="http://docs.python.org/2/library/functions.html#apply" title="apply"><tt class="xref py py-meth docutils literal"><span class="pre">apply()</span></tt></a> method which returns a result object.</p>
<p>If <em>callback</em> is specified then it should be a callable which accepts a
single argument.  When the result becomes ready <em>callback</em> is applied to
it (unless the call failed).  <em>callback</em> should complete immediately since
otherwise the thread which handles the results will get blocked.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.pool.multiprocessing.Pool.map">
<tt class="descname">map</tt><big>(</big><em>func</em>, <em>iterable</em><span class="optional">[</span>, <em>chunksize</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.map" title="Permalink to this definition">¶</a></dt>
<dd><p>A parallel equivalent of the <a class="reference internal" href="http://docs.python.org/2/library/functions.html#map" title="map"><tt class="xref py py-func docutils literal"><span class="pre">map()</span></tt></a> built-in function (it supports only
one <em>iterable</em> argument though).  It blocks until the result is ready.</p>
<p>This method chops the iterable into a number of chunks which it submits to
the process pool as separate tasks.  The (approximate) size of these
chunks can be specified by setting <em>chunksize</em> to a positive integer.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.pool.multiprocessing.Pool.map_async">
<tt class="descname">map_async</tt><big>(</big><em>func</em>, <em>iterable</em><span class="optional">[</span>, <em>chunksize</em><span class="optional">[</span>, <em>callback</em><span class="optional">]</span><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.map_async" title="Permalink to this definition">¶</a></dt>
<dd><p>A variant of the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.map" title="multiprocessing.pool.multiprocessing.Pool.map"><tt class="xref py py-meth docutils literal"><span class="pre">map()</span></tt></a> method which returns a result object.</p>
<p>If <em>callback</em> is specified then it should be a callable which accepts a
single argument.  When the result becomes ready <em>callback</em> is applied to
it (unless the call failed).  <em>callback</em> should complete immediately since
otherwise the thread which handles the results will get blocked.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.pool.multiprocessing.Pool.imap">
<tt class="descname">imap</tt><big>(</big><em>func</em>, <em>iterable</em><span class="optional">[</span>, <em>chunksize</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.imap" title="Permalink to this definition">¶</a></dt>
<dd><p>An equivalent of <a class="reference internal" href="http://docs.python.org/2/library/itertools.html#itertools.imap" title="itertools.imap"><tt class="xref py py-func docutils literal"><span class="pre">itertools.imap()</span></tt></a>.</p>
<p>The <em>chunksize</em> argument is the same as the one used by the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.map" title="multiprocessing.pool.multiprocessing.Pool.map"><tt class="xref py py-meth docutils literal"><span class="pre">map()</span></tt></a>
method.  For very long iterables using a large value for <em>chunksize</em> can
make the job complete <strong>much</strong> faster than using the default value of
<tt class="docutils literal"><span class="pre">1</span></tt>.</p>
<p>Also if <em>chunksize</em> is <tt class="docutils literal"><span class="pre">1</span></tt> then the <tt class="xref py py-meth docutils literal"><span class="pre">next()</span></tt> method of the iterator
returned by the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.imap" title="multiprocessing.pool.multiprocessing.Pool.imap"><tt class="xref py py-meth docutils literal"><span class="pre">imap()</span></tt></a> method has an optional <em>timeout</em> parameter:
<tt class="docutils literal"><span class="pre">next(timeout)</span></tt> will raise <tt class="xref py py-exc docutils literal"><span class="pre">multiprocessing.TimeoutError</span></tt> if the
result cannot be returned within <em>timeout</em> seconds.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.pool.multiprocessing.Pool.imap_unordered">
<tt class="descname">imap_unordered</tt><big>(</big><em>func</em>, <em>iterable</em><span class="optional">[</span>, <em>chunksize</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.imap_unordered" title="Permalink to this definition">¶</a></dt>
<dd><p>The same as <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.imap" title="multiprocessing.pool.multiprocessing.Pool.imap"><tt class="xref py py-meth docutils literal"><span class="pre">imap()</span></tt></a> except that the ordering of the results from the
returned iterator should be considered arbitrary.  (Only when there is
only one worker process is the order guaranteed to be “correct”.)</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.pool.multiprocessing.Pool.close">
<tt class="descname">close</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.close" title="Permalink to this definition">¶</a></dt>
<dd><p>Prevents any more tasks from being submitted to the pool.  Once all the
tasks have been completed the worker processes will exit.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.pool.multiprocessing.Pool.terminate">
<tt class="descname">terminate</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.terminate" title="Permalink to this definition">¶</a></dt>
<dd><p>Stops the worker processes immediately without completing outstanding
work.  When the pool object is garbage collected <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.terminate" title="multiprocessing.pool.multiprocessing.Pool.terminate"><tt class="xref py py-meth docutils literal"><span class="pre">terminate()</span></tt></a> will be
called immediately.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.pool.multiprocessing.Pool.join">
<tt class="descname">join</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.join" title="Permalink to this definition">¶</a></dt>
<dd><p>Wait for the worker processes to exit.  One must call <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.close" title="multiprocessing.pool.multiprocessing.Pool.close"><tt class="xref py py-meth docutils literal"><span class="pre">close()</span></tt></a> or
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.terminate" title="multiprocessing.pool.multiprocessing.Pool.terminate"><tt class="xref py py-meth docutils literal"><span class="pre">terminate()</span></tt></a> before using <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.multiprocessing.Pool.join" title="multiprocessing.pool.multiprocessing.Pool.join"><tt class="xref py py-meth docutils literal"><span class="pre">join()</span></tt></a>.</p>
</dd></dl>

</dd></dl>

<dl class="class">
<dt id="multiprocessing.pool.AsyncResult">
<em class="property">class </em><tt class="descclassname">multiprocessing.pool.</tt><tt class="descname">AsyncResult</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.AsyncResult" title="Permalink to this definition">¶</a></dt>
<dd><p>The class of the result returned by <tt class="xref py py-meth docutils literal"><span class="pre">Pool.apply_async()</span></tt> and
<tt class="xref py py-meth docutils literal"><span class="pre">Pool.map_async()</span></tt>.</p>
<dl class="method">
<dt id="multiprocessing.pool.AsyncResult.get">
<tt class="descname">get</tt><big>(</big><span class="optional">[</span><em>timeout</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.AsyncResult.get" title="Permalink to this definition">¶</a></dt>
<dd><p>Return the result when it arrives.  If <em>timeout</em> is not <tt class="xref docutils literal"><span class="pre">None</span></tt> and the
result does not arrive within <em>timeout</em> seconds then
<tt class="xref py py-exc docutils literal"><span class="pre">multiprocessing.TimeoutError</span></tt> is raised.  If the remote call raised
an exception then that exception will be reraised by <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.AsyncResult.get" title="multiprocessing.pool.AsyncResult.get"><tt class="xref py py-meth docutils literal"><span class="pre">get()</span></tt></a>.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.pool.AsyncResult.wait">
<tt class="descname">wait</tt><big>(</big><span class="optional">[</span><em>timeout</em><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.AsyncResult.wait" title="Permalink to this definition">¶</a></dt>
<dd><p>Wait until the result is available or until <em>timeout</em> seconds pass.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.pool.AsyncResult.ready">
<tt class="descname">ready</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.AsyncResult.ready" title="Permalink to this definition">¶</a></dt>
<dd><p>Return whether the call has completed.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.pool.AsyncResult.successful">
<tt class="descname">successful</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.pool.AsyncResult.successful" title="Permalink to this definition">¶</a></dt>
<dd><p>Return whether the call completed without raising an exception.  Will
raise <a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.AssertionError" title="exceptions.AssertionError"><tt class="xref py py-exc docutils literal"><span class="pre">AssertionError</span></tt></a> if the result is not ready.</p>
</dd></dl>

</dd></dl>

<p>The following example demonstrates the use of a pool:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Pool</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="n">x</span><span class="p">):</span>
    <span class="k">return</span> <span class="n">x</span><span class="o">*</span><span class="n">x</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">pool</span> <span class="o">=</span> <span class="n">Pool</span><span class="p">(</span><span class="n">processes</span><span class="o">=</span><span class="mi">4</span><span class="p">)</span>              <span class="c"># start 4 worker processes</span>

    <span class="n">result</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">apply_async</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="p">(</span><span class="mi">10</span><span class="p">,))</span>    <span class="c"># evaluate "f(10)" asynchronously</span>
    <span class="k">print</span> <span class="n">result</span><span class="o">.</span><span class="n">get</span><span class="p">(</span><span class="n">timeout</span><span class="o">=</span><span class="mi">1</span><span class="p">)</span>           <span class="c"># prints "100" unless your computer is *very* slow</span>

    <span class="k">print</span> <span class="n">pool</span><span class="o">.</span><span class="n">map</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">))</span>          <span class="c"># prints "[0, 1, 4,..., 81]"</span>

    <span class="n">it</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">imap</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">))</span>
    <span class="k">print</span> <span class="n">it</span><span class="o">.</span><span class="n">next</span><span class="p">()</span>                       <span class="c"># prints "0"</span>
    <span class="k">print</span> <span class="n">it</span><span class="o">.</span><span class="n">next</span><span class="p">()</span>                       <span class="c"># prints "1"</span>
    <span class="k">print</span> <span class="n">it</span><span class="o">.</span><span class="n">next</span><span class="p">(</span><span class="n">timeout</span><span class="o">=</span><span class="mi">1</span><span class="p">)</span>              <span class="c"># prints "4" unless your computer is *very* slow</span>

    <span class="kn">import</span> <span class="nn">time</span>
    <span class="n">result</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">apply_async</span><span class="p">(</span><span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">,</span> <span class="p">(</span><span class="mi">10</span><span class="p">,))</span>
    <span class="k">print</span> <span class="n">result</span><span class="o">.</span><span class="n">get</span><span class="p">(</span><span class="n">timeout</span><span class="o">=</span><span class="mi">1</span><span class="p">)</span>           <span class="c"># raises TimeoutError</span>
</pre></div>
</div>
</div>
<div class="section" id="module-multiprocessing.connection">
<span id="listeners-and-clients"></span><span id="multiprocessing-listeners-clients"></span><h3>16.6.2.10. Listeners and Clients<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.connection" title="Permalink to this headline">¶</a></h3>
<p>Usually message passing between processes is done using queues or by using
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection" title="multiprocessing.Connection"><tt class="xref py py-class docutils literal"><span class="pre">Connection</span></tt></a> objects returned by
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Pipe" title="multiprocessing.Pipe"><tt class="xref py py-func docutils literal"><span class="pre">Pipe()</span></tt></a>.</p>
<p>However, the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.connection" title="multiprocessing.connection: API for dealing with sockets."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing.connection</span></tt></a> module allows some extra
flexibility.  It basically gives a high level message oriented API for dealing
with sockets or Windows named pipes, and also has support for <em>digest
authentication</em> using the <a class="reference internal" href="http://docs.python.org/2/library/hmac.html#module-hmac" title="hmac: Keyed-Hashing for Message Authentication (HMAC) implementation for Python."><tt class="xref py py-mod docutils literal"><span class="pre">hmac</span></tt></a> module.</p>
<dl class="function">
<dt id="multiprocessing.connection.deliver_challenge">
<tt class="descclassname">multiprocessing.connection.</tt><tt class="descname">deliver_challenge</tt><big>(</big><em>connection</em>, <em>authkey</em><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.deliver_challenge" title="Permalink to this definition">¶</a></dt>
<dd><p>Send a randomly generated message to the other end of the connection and wait
for a reply.</p>
<p>If the reply matches the digest of the message using <em>authkey</em> as the key
then a welcome message is sent to the other end of the connection.  Otherwise
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.AuthenticationError" title="multiprocessing.connection.AuthenticationError"><tt class="xref py py-exc docutils literal"><span class="pre">AuthenticationError</span></tt></a> is raised.</p>
</dd></dl>

<dl class="function">
<dt id="multiprocessing.connection.answer_challenge">
<tt class="descclassname">multiprocessing.connection.</tt><tt class="descname">answer_challenge</tt><big>(</big><em>connection</em>, <em>authkey</em><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.answer_challenge" title="Permalink to this definition">¶</a></dt>
<dd><p>Receive a message, calculate the digest of the message using <em>authkey</em> as the
key, and then send the digest back.</p>
<p>If a welcome message is not received, then <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.AuthenticationError" title="multiprocessing.connection.AuthenticationError"><tt class="xref py py-exc docutils literal"><span class="pre">AuthenticationError</span></tt></a> is
raised.</p>
</dd></dl>

<dl class="function">
<dt id="multiprocessing.connection.Client">
<tt class="descclassname">multiprocessing.connection.</tt><tt class="descname">Client</tt><big>(</big><em>address</em><span class="optional">[</span>, <em>family</em><span class="optional">[</span>, <em>authenticate</em><span class="optional">[</span>, <em>authkey</em><span class="optional">]</span><span class="optional">]</span><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.Client" title="Permalink to this definition">¶</a></dt>
<dd><p>Attempt to set up a connection to the listener which is using address
<em>address</em>, returning a <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection" title="multiprocessing.Connection"><tt class="xref py py-class docutils literal"><span class="pre">Connection</span></tt></a>.</p>
<p>The type of the connection is determined by <em>family</em> argument, but this can
generally be omitted since it can usually be inferred from the format of
<em>address</em>. (See <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-address-formats"><em>Address Formats</em></a>)</p>
<p>If <em>authenticate</em> is <tt class="xref docutils literal"><span class="pre">True</span></tt> or <em>authkey</em> is a string then digest
authentication is used.  The key used for authentication will be either
<em>authkey</em> or <tt class="docutils literal"><span class="pre">current_process().authkey)</span></tt> if <em>authkey</em> is <tt class="xref docutils literal"><span class="pre">None</span></tt>.
If authentication fails then <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.AuthenticationError" title="multiprocessing.connection.AuthenticationError"><tt class="xref py py-exc docutils literal"><span class="pre">AuthenticationError</span></tt></a> is raised.  See
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-auth-keys"><em>Authentication keys</em></a>.</p>
</dd></dl>

<dl class="class">
<dt id="multiprocessing.connection.Listener">
<em class="property">class </em><tt class="descclassname">multiprocessing.connection.</tt><tt class="descname">Listener</tt><big>(</big><span class="optional">[</span><em>address</em><span class="optional">[</span>, <em>family</em><span class="optional">[</span>, <em>backlog</em><span class="optional">[</span>, <em>authenticate</em><span class="optional">[</span>, <em>authkey</em><span class="optional">]</span><span class="optional">]</span><span class="optional">]</span><span class="optional">]</span><span class="optional">]</span><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.Listener" title="Permalink to this definition">¶</a></dt>
<dd><p>A wrapper for a bound socket or Windows named pipe which is ‘listening’ for
connections.</p>
<p><em>address</em> is the address to be used by the bound socket or named pipe of the
listener object.</p>
<div class="admonition note">
<p class="first admonition-title">Note</p>
<p class="last">If an address of ‘0.0.0.0’ is used, the address will not be a connectable
end point on Windows. If you require a connectable end-point,
you should use ‘127.0.0.1’.</p>
</div>
<p><em>family</em> is the type of socket (or named pipe) to use.  This can be one of
the strings <tt class="docutils literal"><span class="pre">'AF_INET'</span></tt> (for a TCP socket), <tt class="docutils literal"><span class="pre">'AF_UNIX'</span></tt> (for a Unix
domain socket) or <tt class="docutils literal"><span class="pre">'AF_PIPE'</span></tt> (for a Windows named pipe).  Of these only
the first is guaranteed to be available.  If <em>family</em> is <tt class="xref docutils literal"><span class="pre">None</span></tt> then the
family is inferred from the format of <em>address</em>.  If <em>address</em> is also
<tt class="xref docutils literal"><span class="pre">None</span></tt> then a default is chosen.  This default is the family which is
assumed to be the fastest available.  See
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-address-formats"><em>Address Formats</em></a>.  Note that if <em>family</em> is
<tt class="docutils literal"><span class="pre">'AF_UNIX'</span></tt> and address is <tt class="xref docutils literal"><span class="pre">None</span></tt> then the socket will be created in a
private temporary directory created using <a class="reference internal" href="http://docs.python.org/2/library/tempfile.html#tempfile.mkstemp" title="tempfile.mkstemp"><tt class="xref py py-func docutils literal"><span class="pre">tempfile.mkstemp()</span></tt></a>.</p>
<p>If the listener object uses a socket then <em>backlog</em> (1 by default) is passed
to the <a class="reference internal" href="http://docs.python.org/2/library/socket.html#socket.socket.listen" title="socket.socket.listen"><tt class="xref py py-meth docutils literal"><span class="pre">listen()</span></tt></a> method of the socket once it has been
bound.</p>
<p>If <em>authenticate</em> is <tt class="xref docutils literal"><span class="pre">True</span></tt> (<tt class="xref docutils literal"><span class="pre">False</span></tt> by default) or <em>authkey</em> is not
<tt class="xref docutils literal"><span class="pre">None</span></tt> then digest authentication is used.</p>
<p>If <em>authkey</em> is a string then it will be used as the authentication key;
otherwise it must be <em>None</em>.</p>
<p>If <em>authkey</em> is <tt class="xref docutils literal"><span class="pre">None</span></tt> and <em>authenticate</em> is <tt class="xref docutils literal"><span class="pre">True</span></tt> then
<tt class="docutils literal"><span class="pre">current_process().authkey</span></tt> is used as the authentication key.  If
<em>authkey</em> is <tt class="xref docutils literal"><span class="pre">None</span></tt> and <em>authenticate</em> is <tt class="xref docutils literal"><span class="pre">False</span></tt> then no
authentication is done.  If authentication fails then
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.AuthenticationError" title="multiprocessing.connection.AuthenticationError"><tt class="xref py py-exc docutils literal"><span class="pre">AuthenticationError</span></tt></a> is raised.  See <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing-auth-keys"><em>Authentication keys</em></a>.</p>
<dl class="method">
<dt id="multiprocessing.connection.Listener.accept">
<tt class="descname">accept</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.Listener.accept" title="Permalink to this definition">¶</a></dt>
<dd><p>Accept a connection on the bound socket or named pipe of the listener
object and return a <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection" title="multiprocessing.Connection"><tt class="xref py py-class docutils literal"><span class="pre">Connection</span></tt></a> object.  If
authentication is attempted and fails, then
<tt class="xref py py-exc docutils literal"><span class="pre">AuthenticationError</span></tt> is raised.</p>
</dd></dl>

<dl class="method">
<dt id="multiprocessing.connection.Listener.close">
<tt class="descname">close</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.Listener.close" title="Permalink to this definition">¶</a></dt>
<dd><p>Close the bound socket or named pipe of the listener object.  This is
called automatically when the listener is garbage collected.  However it
is advisable to call it explicitly.</p>
</dd></dl>

<p>Listener objects have the following read-only properties:</p>
<dl class="attribute">
<dt id="multiprocessing.connection.Listener.address">
<tt class="descname">address</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.Listener.address" title="Permalink to this definition">¶</a></dt>
<dd><p>The address which is being used by the Listener object.</p>
</dd></dl>

<dl class="attribute">
<dt id="multiprocessing.connection.Listener.last_accepted">
<tt class="descname">last_accepted</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.Listener.last_accepted" title="Permalink to this definition">¶</a></dt>
<dd><p>The address from which the last accepted connection came.  If this is
unavailable then it is <tt class="xref docutils literal"><span class="pre">None</span></tt>.</p>
</dd></dl>

</dd></dl>

<p>The module defines two exceptions:</p>
<dl class="exception">
<dt id="multiprocessing.connection.AuthenticationError">
<em class="property">exception </em><tt class="descclassname">multiprocessing.connection.</tt><tt class="descname">AuthenticationError</tt><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.AuthenticationError" title="Permalink to this definition">¶</a></dt>
<dd><p>Exception raised when there is an authentication error.</p>
</dd></dl>

<p><strong>Examples</strong></p>
<p>The following server code creates a listener which uses <tt class="docutils literal"><span class="pre">'secret</span> <span class="pre">password'</span></tt> as
an authentication key.  It then waits for a connection and sends some data to
the client:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing.connection</span> <span class="kn">import</span> <span class="n">Listener</span>
<span class="kn">from</span> <span class="nn">array</span> <span class="kn">import</span> <span class="n">array</span>

<span class="n">address</span> <span class="o">=</span> <span class="p">(</span><span class="s">'localhost'</span><span class="p">,</span> <span class="mi">6000</span><span class="p">)</span>     <span class="c"># family is deduced to be 'AF_INET'</span>
<span class="n">listener</span> <span class="o">=</span> <span class="n">Listener</span><span class="p">(</span><span class="n">address</span><span class="p">,</span> <span class="n">authkey</span><span class="o">=</span><span class="s">'secret password'</span><span class="p">)</span>

<span class="n">conn</span> <span class="o">=</span> <span class="n">listener</span><span class="o">.</span><span class="n">accept</span><span class="p">()</span>
<span class="k">print</span> <span class="s">'connection accepted from'</span><span class="p">,</span> <span class="n">listener</span><span class="o">.</span><span class="n">last_accepted</span>

<span class="n">conn</span><span class="o">.</span><span class="n">send</span><span class="p">([</span><span class="mf">2.25</span><span class="p">,</span> <span class="bp">None</span><span class="p">,</span> <span class="s">'junk'</span><span class="p">,</span> <span class="nb">float</span><span class="p">])</span>

<span class="n">conn</span><span class="o">.</span><span class="n">send_bytes</span><span class="p">(</span><span class="s">'hello'</span><span class="p">)</span>

<span class="n">conn</span><span class="o">.</span><span class="n">send_bytes</span><span class="p">(</span><span class="n">array</span><span class="p">(</span><span class="s">'i'</span><span class="p">,</span> <span class="p">[</span><span class="mi">42</span><span class="p">,</span> <span class="mi">1729</span><span class="p">]))</span>

<span class="n">conn</span><span class="o">.</span><span class="n">close</span><span class="p">()</span>
<span class="n">listener</span><span class="o">.</span><span class="n">close</span><span class="p">()</span>
</pre></div>
</div>
<p>The following code connects to the server and receives some data from the
server:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing.connection</span> <span class="kn">import</span> <span class="n">Client</span>
<span class="kn">from</span> <span class="nn">array</span> <span class="kn">import</span> <span class="n">array</span>

<span class="n">address</span> <span class="o">=</span> <span class="p">(</span><span class="s">'localhost'</span><span class="p">,</span> <span class="mi">6000</span><span class="p">)</span>
<span class="n">conn</span> <span class="o">=</span> <span class="n">Client</span><span class="p">(</span><span class="n">address</span><span class="p">,</span> <span class="n">authkey</span><span class="o">=</span><span class="s">'secret password'</span><span class="p">)</span>

<span class="k">print</span> <span class="n">conn</span><span class="o">.</span><span class="n">recv</span><span class="p">()</span>                 <span class="c"># =&gt; [2.25, None, 'junk', float]</span>

<span class="k">print</span> <span class="n">conn</span><span class="o">.</span><span class="n">recv_bytes</span><span class="p">()</span>            <span class="c"># =&gt; 'hello'</span>

<span class="n">arr</span> <span class="o">=</span> <span class="n">array</span><span class="p">(</span><span class="s">'i'</span><span class="p">,</span> <span class="p">[</span><span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">])</span>
<span class="k">print</span> <span class="n">conn</span><span class="o">.</span><span class="n">recv_bytes_into</span><span class="p">(</span><span class="n">arr</span><span class="p">)</span>     <span class="c"># =&gt; 8</span>
<span class="k">print</span> <span class="n">arr</span>                         <span class="c"># =&gt; array('i', [42, 1729, 0, 0, 0])</span>

<span class="n">conn</span><span class="o">.</span><span class="n">close</span><span class="p">()</span>
</pre></div>
</div>
<div class="section" id="address-formats">
<span id="multiprocessing-address-formats"></span><h4>16.6.2.10.1. Address Formats<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#address-formats" title="Permalink to this headline">¶</a></h4>
<ul>
<li><p class="first">An <tt class="docutils literal"><span class="pre">'AF_INET'</span></tt> address is a tuple of the form <tt class="docutils literal"><span class="pre">(hostname,</span> <span class="pre">port)</span></tt> where
<em>hostname</em> is a string and <em>port</em> is an integer.</p>
</li>
<li><p class="first">An <tt class="docutils literal"><span class="pre">'AF_UNIX'</span></tt> address is a string representing a filename on the
filesystem.</p>
</li>
<li><dl class="first docutils">
<dt>An <tt class="docutils literal"><span class="pre">'AF_PIPE'</span></tt> address is a string of the form</dt>
<dd><p class="first last"><tt class="samp docutils literal"><span class="pre">r'\\.\pipe\</span><em><span class="pre">PipeName</span></em><span class="pre">'</span></tt>.  To use <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.Client" title="multiprocessing.connection.Client"><tt class="xref py py-func docutils literal"><span class="pre">Client()</span></tt></a> to connect to a named
pipe on a remote computer called <em>ServerName</em> one should use an address of the
form <tt class="samp docutils literal"><span class="pre">r'\\</span><em><span class="pre">ServerName</span></em><span class="pre">\pipe\</span><em><span class="pre">PipeName</span></em><span class="pre">'</span></tt> instead.</p>
</dd>
</dl>
</li>
</ul>
<p>Note that any string beginning with two backslashes is assumed by default to be
an <tt class="docutils literal"><span class="pre">'AF_PIPE'</span></tt> address rather than an <tt class="docutils literal"><span class="pre">'AF_UNIX'</span></tt> address.</p>
</div>
</div>
<div class="section" id="authentication-keys">
<span id="multiprocessing-auth-keys"></span><h3>16.6.2.11. Authentication keys<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#authentication-keys" title="Permalink to this headline">¶</a></h3>
<p>When one uses <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Connection.recv" title="multiprocessing.Connection.recv"><tt class="xref py py-meth docutils literal"><span class="pre">Connection.recv</span></tt></a>, the
data received is automatically
unpickled.  Unfortunately unpickling data from an untrusted source is a security
risk.  Therefore <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.Listener" title="multiprocessing.connection.Listener"><tt class="xref py py-class docutils literal"><span class="pre">Listener</span></tt></a> and <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.connection.Client" title="multiprocessing.connection.Client"><tt class="xref py py-func docutils literal"><span class="pre">Client()</span></tt></a> use the <a class="reference internal" href="http://docs.python.org/2/library/hmac.html#module-hmac" title="hmac: Keyed-Hashing for Message Authentication (HMAC) implementation for Python."><tt class="xref py py-mod docutils literal"><span class="pre">hmac</span></tt></a> module
to provide digest authentication.</p>
<p>An authentication key is a string which can be thought of as a password: once a
connection is established both ends will demand proof that the other knows the
authentication key.  (Demonstrating that both ends are using the same key does
<strong>not</strong> involve sending the key over the connection.)</p>
<p>If authentication is requested but do authentication key is specified then the
return value of <tt class="docutils literal"><span class="pre">current_process().authkey</span></tt> is used (see
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process" title="multiprocessing.Process"><tt class="xref py py-class docutils literal"><span class="pre">Process</span></tt></a>).  This value will automatically inherited by
any <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process" title="multiprocessing.Process"><tt class="xref py py-class docutils literal"><span class="pre">Process</span></tt></a> object that the current process creates.
This means that (by default) all processes of a multi-process program will share
a single authentication key which can be used when setting up connections
between themselves.</p>
<p>Suitable authentication keys can also be generated by using <a class="reference internal" href="http://docs.python.org/2/library/os.html#os.urandom" title="os.urandom"><tt class="xref py py-func docutils literal"><span class="pre">os.urandom()</span></tt></a>.</p>
</div>
<div class="section" id="logging">
<h3>16.6.2.12. Logging<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#logging" title="Permalink to this headline">¶</a></h3>
<p>Some support for logging is available.  Note, however, that the <a class="reference internal" href="http://docs.python.org/2/library/logging.html#module-logging" title="logging: Flexible event logging system for applications."><tt class="xref py py-mod docutils literal"><span class="pre">logging</span></tt></a>
package does not use process shared locks so it is possible (depending on the
handler type) for messages from different processes to get mixed up.</p>
<dl class="function">
<dt id="multiprocessing.get_logger">
<tt class="descclassname">multiprocessing.</tt><tt class="descname">get_logger</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.get_logger" title="Permalink to this definition">¶</a></dt>
<dd><p>Returns the logger used by <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a>.  If necessary, a new one
will be created.</p>
<p>When first created the logger has level <tt class="xref py py-data docutils literal"><span class="pre">logging.NOTSET</span></tt> and no
default handler. Messages sent to this logger will not by default propagate
to the root logger.</p>
<p>Note that on Windows child processes will only inherit the level of the
parent process’s logger – any other customization of the logger will not be
inherited.</p>
</dd></dl>

<dl class="function">
<dt id="multiprocessing.log_to_stderr">
<tt class="descclassname">multiprocessing.</tt><tt class="descname">log_to_stderr</tt><big>(</big><big>)</big><a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.log_to_stderr" title="Permalink to this definition">¶</a></dt>
<dd><p>This function performs a call to <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.get_logger" title="multiprocessing.get_logger"><tt class="xref py py-func docutils literal"><span class="pre">get_logger()</span></tt></a> but in addition to
returning the logger created by get_logger, it adds a handler which sends
output to <a class="reference internal" href="http://docs.python.org/2/library/sys.html#sys.stderr" title="sys.stderr"><tt class="xref py py-data docutils literal"><span class="pre">sys.stderr</span></tt></a> using format
<tt class="docutils literal"><span class="pre">'[%(levelname)s/%(processName)s]</span> <span class="pre">%(message)s'</span></tt>.</p>
</dd></dl>

<p>Below is an example session with logging turned on:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="kn">import</span> <span class="nn">multiprocessing</span><span class="o">,</span> <span class="nn">logging</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">logger</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">log_to_stderr</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">logger</span><span class="o">.</span><span class="n">setLevel</span><span class="p">(</span><span class="n">logging</span><span class="o">.</span><span class="n">INFO</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">logger</span><span class="o">.</span><span class="n">warning</span><span class="p">(</span><span class="s">'doomed'</span><span class="p">)</span>
<span class="go">[WARNING/MainProcess] doomed</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">m</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Manager</span><span class="p">()</span>
<span class="go">[INFO/SyncManager-...] child process calling self.run()</span>
<span class="go">[INFO/SyncManager-...] created temp directory /.../pymp-...</span>
<span class="go">[INFO/SyncManager-...] manager serving at '/.../listener-...'</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">del</span> <span class="n">m</span>
<span class="go">[INFO/MainProcess] sending shutdown message to manager</span>
<span class="go">[INFO/SyncManager-...] manager exiting with exitcode 0</span>
</pre></div>
</div>
<p>In addition to having these two logging functions, the multiprocessing also
exposes two additional logging level attributes. These are  <tt class="xref py py-const docutils literal"><span class="pre">SUBWARNING</span></tt>
and <tt class="xref py py-const docutils literal"><span class="pre">SUBDEBUG</span></tt>. The table below illustrates where theses fit in the
normal level hierarchy.</p>
<table border="1" class="docutils">
<colgroup>
<col width="50%">
<col width="50%">
</colgroup>
<thead valign="bottom">
<tr><th class="head">Level</th>
<th class="head">Numeric value</th>
</tr>
</thead>
<tbody valign="top">
<tr><td><tt class="docutils literal"><span class="pre">SUBWARNING</span></tt></td>
<td>25</td>
</tr>
<tr><td><tt class="docutils literal"><span class="pre">SUBDEBUG</span></tt></td>
<td>5</td>
</tr>
</tbody>
</table>
<p>For a full table of logging levels, see the <a class="reference internal" href="http://docs.python.org/2/library/logging.html#module-logging" title="logging: Flexible event logging system for applications."><tt class="xref py py-mod docutils literal"><span class="pre">logging</span></tt></a> module.</p>
<p>These additional logging levels are used primarily for certain debug messages
within the multiprocessing module. Below is the same example as above, except
with <tt class="xref py py-const docutils literal"><span class="pre">SUBDEBUG</span></tt> enabled:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><span class="copybutton" title="Hide the prompts and output" style="cursor: pointer; position: absolute; top: 0px; right: 0px; border: 1px solid rgb(170, 204, 153); color: rgb(170, 204, 153); font-family: monospace; padding-left: 0.2em; padding-right: 0.2em;">&gt;&gt;&gt;</span><pre><span class="gp">&gt;&gt;&gt; </span><span class="kn">import</span> <span class="nn">multiprocessing</span><span class="o">,</span> <span class="nn">logging</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">logger</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">log_to_stderr</span><span class="p">()</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">logger</span><span class="o">.</span><span class="n">setLevel</span><span class="p">(</span><span class="n">multiprocessing</span><span class="o">.</span><span class="n">SUBDEBUG</span><span class="p">)</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">logger</span><span class="o">.</span><span class="n">warning</span><span class="p">(</span><span class="s">'doomed'</span><span class="p">)</span>
<span class="go">[WARNING/MainProcess] doomed</span>
<span class="gp">&gt;&gt;&gt; </span><span class="n">m</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Manager</span><span class="p">()</span>
<span class="go">[INFO/SyncManager-...] child process calling self.run()</span>
<span class="go">[INFO/SyncManager-...] created temp directory /.../pymp-...</span>
<span class="go">[INFO/SyncManager-...] manager serving at '/.../pymp-djGBXN/listener-...'</span>
<span class="gp">&gt;&gt;&gt; </span><span class="k">del</span> <span class="n">m</span>
<span class="go">[SUBDEBUG/MainProcess] finalizer calling ...</span>
<span class="go">[INFO/MainProcess] sending shutdown message to manager</span>
<span class="go">[DEBUG/SyncManager-...] manager received shutdown message</span>
<span class="go">[SUBDEBUG/SyncManager-...] calling &lt;Finalize object, callback=unlink, ...</span>
<span class="go">[SUBDEBUG/SyncManager-...] finalizer calling &lt;built-in function unlink&gt; ...</span>
<span class="go">[SUBDEBUG/SyncManager-...] calling &lt;Finalize object, dead&gt;</span>
<span class="go">[SUBDEBUG/SyncManager-...] finalizer calling &lt;function rmtree at 0x5aa730&gt; ...</span>
<span class="go">[INFO/SyncManager-...] manager exiting with exitcode 0</span>
</pre></div>
</div>
</div>
<div class="section" id="module-multiprocessing.dummy">
<span id="the-multiprocessing-dummy-module"></span><h3>16.6.2.13. The <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.dummy" title="multiprocessing.dummy: Dumb wrapper around threading."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing.dummy</span></tt></a> module<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.dummy" title="Permalink to this headline">¶</a></h3>
<p><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.dummy" title="multiprocessing.dummy: Dumb wrapper around threading."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing.dummy</span></tt></a> replicates the API of <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> but is
no more than a wrapper around the <a class="reference internal" href="http://docs.python.org/2/library/threading.html#module-threading" title="threading: Higher-level threading interface."><tt class="xref py py-mod docutils literal"><span class="pre">threading</span></tt></a> module.</p>
</div>
</div>
<div class="section" id="programming-guidelines">
<span id="multiprocessing-programming"></span><h2>16.6.3. Programming guidelines<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#programming-guidelines" title="Permalink to this headline">¶</a></h2>
<p>There are certain guidelines and idioms which should be adhered to when using
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a>.</p>
<div class="section" id="all-platforms">
<h3>16.6.3.1. All platforms<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#all-platforms" title="Permalink to this headline">¶</a></h3>
<p>Avoid shared state</p>
<blockquote>
<div><p>As far as possible one should try to avoid shifting large amounts of data
between processes.</p>
<p>It is probably best to stick to using queues or pipes for communication
between processes rather than using the lower level synchronization
primitives from the <a class="reference internal" href="http://docs.python.org/2/library/threading.html#module-threading" title="threading: Higher-level threading interface."><tt class="xref py py-mod docutils literal"><span class="pre">threading</span></tt></a> module.</p>
</div></blockquote>
<p>Picklability</p>
<blockquote>
<div>Ensure that the arguments to the methods of proxies are picklable.</div></blockquote>
<p>Thread safety of proxies</p>
<blockquote>
<div><p>Do not use a proxy object from more than one thread unless you protect it
with a lock.</p>
<p>(There is never a problem with different processes using the <em>same</em> proxy.)</p>
</div></blockquote>
<p>Joining zombie processes</p>
<blockquote>
<div>On Unix when a process finishes but has not been joined it becomes a zombie.
There should never be very many because each time a new process starts (or
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.active_children" title="multiprocessing.active_children"><tt class="xref py py-func docutils literal"><span class="pre">active_children()</span></tt></a> is called) all completed processes
which have not yet been joined will be joined.  Also calling a finished
process’s <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.is_alive" title="multiprocessing.Process.is_alive"><tt class="xref py py-meth docutils literal"><span class="pre">Process.is_alive</span></tt></a> will
join the process.  Even so it is probably good
practice to explicitly join all the processes that you start.</div></blockquote>
<p>Better to inherit than pickle/unpickle</p>
<blockquote>
<div>On Windows many types from <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> need to be picklable so
that child processes can use them.  However, one should generally avoid
sending shared objects to other processes using pipes or queues.  Instead
you should arrange the program so that a process which needs access to a
shared resource created elsewhere can inherit it from an ancestor process.</div></blockquote>
<p>Avoid terminating processes</p>
<blockquote>
<div><p>Using the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.terminate" title="multiprocessing.Process.terminate"><tt class="xref py py-meth docutils literal"><span class="pre">Process.terminate</span></tt></a>
method to stop a process is liable to
cause any shared resources (such as locks, semaphores, pipes and queues)
currently being used by the process to become broken or unavailable to other
processes.</p>
<p>Therefore it is probably best to only consider using
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.terminate" title="multiprocessing.Process.terminate"><tt class="xref py py-meth docutils literal"><span class="pre">Process.terminate</span></tt></a> on processes
which never use any shared resources.</p>
</div></blockquote>
<p>Joining processes that use queues</p>
<blockquote>
<div><p>Bear in mind that a process that has put items in a queue will wait before
terminating until all the buffered items are fed by the “feeder” thread to
the underlying pipe.  (The child process can call the
<a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Queue.cancel_join_thread" title="multiprocessing.Queue.cancel_join_thread"><tt class="xref py py-meth docutils literal"><span class="pre">cancel_join_thread()</span></tt></a> method of the queue to avoid this behaviour.)</p>
<p>This means that whenever you use a queue you need to make sure that all
items which have been put on the queue will eventually be removed before the
process is joined.  Otherwise you cannot be sure that processes which have
put items on the queue will terminate.  Remember also that non-daemonic
processes will be automatically be joined.</p>
<p>An example which will deadlock is the following:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">Queue</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="n">q</span><span class="p">):</span>
    <span class="n">q</span><span class="o">.</span><span class="n">put</span><span class="p">(</span><span class="s">'X'</span> <span class="o">*</span> <span class="mi">1000000</span><span class="p">)</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">queue</span> <span class="o">=</span> <span class="n">Queue</span><span class="p">()</span>
    <span class="n">p</span> <span class="o">=</span> <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">f</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">queue</span><span class="p">,))</span>
    <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
    <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>                    <span class="c"># this deadlocks</span>
    <span class="n">obj</span> <span class="o">=</span> <span class="n">queue</span><span class="o">.</span><span class="n">get</span><span class="p">()</span>
</pre></div>
</div>
<p>A fix here would be to swap the last two lines round (or simply remove the
<tt class="docutils literal"><span class="pre">p.join()</span></tt> line).</p>
</div></blockquote>
<p>Explicitly pass resources to child processes</p>
<blockquote>
<div><p>On Unix a child process can make use of a shared resource created in a
parent process using a global resource.  However, it is better to pass the
object as an argument to the constructor for the child process.</p>
<p>Apart from making the code (potentially) compatible with Windows this also
ensures that as long as the child process is still alive the object will not
be garbage collected in the parent process.  This might be important if some
resource is freed when the object is garbage collected in the parent
process.</p>
<p>So for instance</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">Lock</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">():</span>
    <span class="o">...</span> <span class="n">do</span> <span class="n">something</span> <span class="n">using</span> <span class="s">"lock"</span> <span class="o">...</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
   <span class="n">lock</span> <span class="o">=</span> <span class="n">Lock</span><span class="p">()</span>
   <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">):</span>
        <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">f</span><span class="p">)</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
</pre></div>
</div>
<p>should be rewritten as</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">Lock</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="n">l</span><span class="p">):</span>
    <span class="o">...</span> <span class="n">do</span> <span class="n">something</span> <span class="n">using</span> <span class="s">"l"</span> <span class="o">...</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
   <span class="n">lock</span> <span class="o">=</span> <span class="n">Lock</span><span class="p">()</span>
   <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">):</span>
        <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">f</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">lock</span><span class="p">,))</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
</pre></div>
</div>
</div></blockquote>
<p>Beware of replacing <a class="reference internal" href="http://docs.python.org/2/library/sys.html#sys.stdin" title="sys.stdin"><tt class="xref py py-data docutils literal"><span class="pre">sys.stdin</span></tt></a> with a “file like object”</p>
<blockquote>
<div><p><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> originally unconditionally called:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="n">os</span><span class="o">.</span><span class="n">close</span><span class="p">(</span><span class="n">sys</span><span class="o">.</span><span class="n">stdin</span><span class="o">.</span><span class="n">fileno</span><span class="p">())</span>
</pre></div>
</div>
<p>in the <tt class="xref py py-meth docutils literal"><span class="pre">multiprocessing.Process._bootstrap()</span></tt> method — this resulted
in issues with processes-in-processes. This has been changed to:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="n">sys</span><span class="o">.</span><span class="n">stdin</span><span class="o">.</span><span class="n">close</span><span class="p">()</span>
<span class="n">sys</span><span class="o">.</span><span class="n">stdin</span> <span class="o">=</span> <span class="nb">open</span><span class="p">(</span><span class="n">os</span><span class="o">.</span><span class="n">devnull</span><span class="p">)</span>
</pre></div>
</div>
<p>Which solves the fundamental issue of processes colliding with each other
resulting in a bad file descriptor error, but introduces a potential danger
to applications which replace <a class="reference internal" href="http://docs.python.org/2/library/sys.html#sys.stdin" title="sys.stdin"><tt class="xref py py-func docutils literal"><span class="pre">sys.stdin()</span></tt></a> with a “file-like object”
with output buffering.  This danger is that if multiple processes call
<a class="reference internal" href="http://docs.python.org/2/library/io.html#io.IOBase.close" title="io.IOBase.close"><tt class="xref py py-meth docutils literal"><span class="pre">close()</span></tt></a> on this file-like object, it could result in the same
data being flushed to the object multiple times, resulting in corruption.</p>
<p>If you write a file-like object and implement your own caching, you can
make it fork-safe by storing the pid whenever you append to the cache,
and discarding the cache when the pid changes. For example:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="nd">@property</span>
<span class="k">def</span> <span class="nf">cache</span><span class="p">(</span><span class="bp">self</span><span class="p">):</span>
    <span class="n">pid</span> <span class="o">=</span> <span class="n">os</span><span class="o">.</span><span class="n">getpid</span><span class="p">()</span>
    <span class="k">if</span> <span class="n">pid</span> <span class="o">!=</span> <span class="bp">self</span><span class="o">.</span><span class="n">_pid</span><span class="p">:</span>
        <span class="bp">self</span><span class="o">.</span><span class="n">_pid</span> <span class="o">=</span> <span class="n">pid</span>
        <span class="bp">self</span><span class="o">.</span><span class="n">_cache</span> <span class="o">=</span> <span class="p">[]</span>
    <span class="k">return</span> <span class="bp">self</span><span class="o">.</span><span class="n">_cache</span>
</pre></div>
</div>
<p>For more information, see <a class="reference external" href="http://bugs.python.org/issue5155">issue 5155</a>, <a class="reference external" href="http://bugs.python.org/issue5313">issue 5313</a> and <a class="reference external" href="http://bugs.python.org/issue5331">issue 5331</a></p>
</div></blockquote>
</div>
<div class="section" id="windows">
<h3>16.6.3.2. Windows<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#windows" title="Permalink to this headline">¶</a></h3>
<p>Since Windows lacks <a class="reference internal" href="http://docs.python.org/2/library/os.html#os.fork" title="os.fork"><tt class="xref py py-func docutils literal"><span class="pre">os.fork()</span></tt></a> it has a few extra restrictions:</p>
<p>More picklability</p>
<blockquote>
<div><p>Ensure that all arguments to <tt class="xref py py-meth docutils literal"><span class="pre">Process.__init__()</span></tt> are picklable.  This
means, in particular, that bound or unbound methods cannot be used directly
as the <tt class="docutils literal"><span class="pre">target</span></tt> argument on Windows — just define a function and use
that instead.</p>
<p>Also, if you subclass <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process" title="multiprocessing.Process"><tt class="xref py py-class docutils literal"><span class="pre">Process</span></tt></a> then make sure that
instances will be picklable when the <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.start" title="multiprocessing.Process.start"><tt class="xref py py-meth docutils literal"><span class="pre">Process.start</span></tt></a> method is called.</p>
</div></blockquote>
<p>Global variables</p>
<blockquote>
<div><p>Bear in mind that if code run in a child process tries to access a global
variable, then the value it sees (if any) may not be the same as the value
in the parent process at the time that <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#multiprocessing.Process.start" title="multiprocessing.Process.start"><tt class="xref py py-meth docutils literal"><span class="pre">Process.start</span></tt></a> was called.</p>
<p>However, global variables which are just module level constants cause no
problems.</p>
</div></blockquote>
<p>Safe importing of main module</p>
<blockquote>
<div><p>Make sure that the main module can be safely imported by a new Python
interpreter without causing unintended side effects (such a starting a new
process).</p>
<p>For example, under Windows running the following module would fail with a
<a class="reference internal" href="http://docs.python.org/2/library/exceptions.html#exceptions.RuntimeError" title="exceptions.RuntimeError"><tt class="xref py py-exc docutils literal"><span class="pre">RuntimeError</span></tt></a>:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span>

<span class="k">def</span> <span class="nf">foo</span><span class="p">():</span>
    <span class="k">print</span> <span class="s">'hello'</span>

<span class="n">p</span> <span class="o">=</span> <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">foo</span><span class="p">)</span>
<span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
</pre></div>
</div>
<p>Instead one should protect the “entry point” of the program by using <tt class="docutils literal"><span class="pre">if</span>
<span class="pre">__name__</span> <span class="pre">==</span> <span class="pre">'__main__':</span></tt> as follows:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">freeze_support</span>

<span class="k">def</span> <span class="nf">foo</span><span class="p">():</span>
    <span class="k">print</span> <span class="s">'hello'</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">freeze_support</span><span class="p">()</span>
    <span class="n">p</span> <span class="o">=</span> <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">foo</span><span class="p">)</span>
    <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
</pre></div>
</div>
<p>(The <tt class="docutils literal"><span class="pre">freeze_support()</span></tt> line can be omitted if the program will be run
normally instead of frozen.)</p>
<p>This allows the newly spawned Python interpreter to safely import the module
and then run the module’s <tt class="docutils literal"><span class="pre">foo()</span></tt> function.</p>
<p>Similar restrictions apply if a pool or manager is created in the main
module.</p>
</div></blockquote>
</div>
</div>
<div class="section" id="examples">
<span id="multiprocessing-examples"></span><h2>16.6.4. Examples<a class="headerlink" href="http://docs.python.org/2/library/multiprocessing.html#examples" title="Permalink to this headline">¶</a></h2>
<p>Demonstration of how to create and use customized managers and proxies:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="c">#</span>
<span class="c"># This module shows how to use arbitrary callables with a subclass of</span>
<span class="c"># `BaseManager`.</span>
<span class="c">#</span>
<span class="c"># Copyright (c) 2006-2008, R Oudkerk</span>
<span class="c"># All rights reserved.</span>
<span class="c">#</span>

<span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">freeze_support</span>
<span class="kn">from</span> <span class="nn">multiprocessing.managers</span> <span class="kn">import</span> <span class="n">BaseManager</span><span class="p">,</span> <span class="n">BaseProxy</span>
<span class="kn">import</span> <span class="nn">operator</span>

<span class="c">##</span>

<span class="k">class</span> <span class="nc">Foo</span><span class="p">(</span><span class="nb">object</span><span class="p">):</span>
    <span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="bp">self</span><span class="p">):</span>
        <span class="k">print</span> <span class="s">'you called Foo.f()'</span>
    <span class="k">def</span> <span class="nf">g</span><span class="p">(</span><span class="bp">self</span><span class="p">):</span>
        <span class="k">print</span> <span class="s">'you called Foo.g()'</span>
    <span class="k">def</span> <span class="nf">_h</span><span class="p">(</span><span class="bp">self</span><span class="p">):</span>
        <span class="k">print</span> <span class="s">'you called Foo._h()'</span>

<span class="c"># A simple generator function</span>
<span class="k">def</span> <span class="nf">baz</span><span class="p">():</span>
    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">xrange</span><span class="p">(</span><span class="mi">10</span><span class="p">):</span>
        <span class="k">yield</span> <span class="n">i</span><span class="o">*</span><span class="n">i</span>

<span class="c"># Proxy type for generator objects</span>
<span class="k">class</span> <span class="nc">GeneratorProxy</span><span class="p">(</span><span class="n">BaseProxy</span><span class="p">):</span>
    <span class="n">_exposed_</span> <span class="o">=</span> <span class="p">(</span><span class="s">'next'</span><span class="p">,</span> <span class="s">'__next__'</span><span class="p">)</span>
    <span class="k">def</span> <span class="nf">__iter__</span><span class="p">(</span><span class="bp">self</span><span class="p">):</span>
        <span class="k">return</span> <span class="bp">self</span>
    <span class="k">def</span> <span class="nf">next</span><span class="p">(</span><span class="bp">self</span><span class="p">):</span>
        <span class="k">return</span> <span class="bp">self</span><span class="o">.</span><span class="n">_callmethod</span><span class="p">(</span><span class="s">'next'</span><span class="p">)</span>
    <span class="k">def</span> <span class="nf">__next__</span><span class="p">(</span><span class="bp">self</span><span class="p">):</span>
        <span class="k">return</span> <span class="bp">self</span><span class="o">.</span><span class="n">_callmethod</span><span class="p">(</span><span class="s">'__next__'</span><span class="p">)</span>

<span class="c"># Function to return the operator module</span>
<span class="k">def</span> <span class="nf">get_operator_module</span><span class="p">():</span>
    <span class="k">return</span> <span class="n">operator</span>

<span class="c">##</span>

<span class="k">class</span> <span class="nc">MyManager</span><span class="p">(</span><span class="n">BaseManager</span><span class="p">):</span>
    <span class="k">pass</span>

<span class="c"># register the Foo class; make `f()` and `g()` accessible via proxy</span>
<span class="n">MyManager</span><span class="o">.</span><span class="n">register</span><span class="p">(</span><span class="s">'Foo1'</span><span class="p">,</span> <span class="n">Foo</span><span class="p">)</span>

<span class="c"># register the Foo class; make `g()` and `_h()` accessible via proxy</span>
<span class="n">MyManager</span><span class="o">.</span><span class="n">register</span><span class="p">(</span><span class="s">'Foo2'</span><span class="p">,</span> <span class="n">Foo</span><span class="p">,</span> <span class="n">exposed</span><span class="o">=</span><span class="p">(</span><span class="s">'g'</span><span class="p">,</span> <span class="s">'_h'</span><span class="p">))</span>

<span class="c"># register the generator function baz; use `GeneratorProxy` to make proxies</span>
<span class="n">MyManager</span><span class="o">.</span><span class="n">register</span><span class="p">(</span><span class="s">'baz'</span><span class="p">,</span> <span class="n">baz</span><span class="p">,</span> <span class="n">proxytype</span><span class="o">=</span><span class="n">GeneratorProxy</span><span class="p">)</span>

<span class="c"># register get_operator_module(); make public functions accessible via proxy</span>
<span class="n">MyManager</span><span class="o">.</span><span class="n">register</span><span class="p">(</span><span class="s">'operator'</span><span class="p">,</span> <span class="n">get_operator_module</span><span class="p">)</span>

<span class="c">##</span>

<span class="k">def</span> <span class="nf">test</span><span class="p">():</span>
    <span class="n">manager</span> <span class="o">=</span> <span class="n">MyManager</span><span class="p">()</span>
    <span class="n">manager</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>

    <span class="k">print</span> <span class="s">'-'</span> <span class="o">*</span> <span class="mi">20</span>

    <span class="n">f1</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">Foo1</span><span class="p">()</span>
    <span class="n">f1</span><span class="o">.</span><span class="n">f</span><span class="p">()</span>
    <span class="n">f1</span><span class="o">.</span><span class="n">g</span><span class="p">()</span>
    <span class="k">assert</span> <span class="ow">not</span> <span class="nb">hasattr</span><span class="p">(</span><span class="n">f1</span><span class="p">,</span> <span class="s">'_h'</span><span class="p">)</span>
    <span class="k">assert</span> <span class="nb">sorted</span><span class="p">(</span><span class="n">f1</span><span class="o">.</span><span class="n">_exposed_</span><span class="p">)</span> <span class="o">==</span> <span class="nb">sorted</span><span class="p">([</span><span class="s">'f'</span><span class="p">,</span> <span class="s">'g'</span><span class="p">])</span>

    <span class="k">print</span> <span class="s">'-'</span> <span class="o">*</span> <span class="mi">20</span>

    <span class="n">f2</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">Foo2</span><span class="p">()</span>
    <span class="n">f2</span><span class="o">.</span><span class="n">g</span><span class="p">()</span>
    <span class="n">f2</span><span class="o">.</span><span class="n">_h</span><span class="p">()</span>
    <span class="k">assert</span> <span class="ow">not</span> <span class="nb">hasattr</span><span class="p">(</span><span class="n">f2</span><span class="p">,</span> <span class="s">'f'</span><span class="p">)</span>
    <span class="k">assert</span> <span class="nb">sorted</span><span class="p">(</span><span class="n">f2</span><span class="o">.</span><span class="n">_exposed_</span><span class="p">)</span> <span class="o">==</span> <span class="nb">sorted</span><span class="p">([</span><span class="s">'g'</span><span class="p">,</span> <span class="s">'_h'</span><span class="p">])</span>

    <span class="k">print</span> <span class="s">'-'</span> <span class="o">*</span> <span class="mi">20</span>

    <span class="n">it</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">baz</span><span class="p">()</span>
    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="n">it</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">'&lt;</span><span class="si">%d</span><span class="s">&gt;'</span> <span class="o">%</span> <span class="n">i</span><span class="p">,</span>
    <span class="k">print</span>

    <span class="k">print</span> <span class="s">'-'</span> <span class="o">*</span> <span class="mi">20</span>

    <span class="n">op</span> <span class="o">=</span> <span class="n">manager</span><span class="o">.</span><span class="n">operator</span><span class="p">()</span>
    <span class="k">print</span> <span class="s">'op.add(23, 45) ='</span><span class="p">,</span> <span class="n">op</span><span class="o">.</span><span class="n">add</span><span class="p">(</span><span class="mi">23</span><span class="p">,</span> <span class="mi">45</span><span class="p">)</span>
    <span class="k">print</span> <span class="s">'op.pow(2, 94) ='</span><span class="p">,</span> <span class="n">op</span><span class="o">.</span><span class="n">pow</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span> <span class="mi">94</span><span class="p">)</span>
    <span class="k">print</span> <span class="s">'op.getslice(range(10), 2, 6) ='</span><span class="p">,</span> <span class="n">op</span><span class="o">.</span><span class="n">getslice</span><span class="p">(</span><span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">),</span> <span class="mi">2</span><span class="p">,</span> <span class="mi">6</span><span class="p">)</span>
    <span class="k">print</span> <span class="s">'op.repeat(range(5), 3) ='</span><span class="p">,</span> <span class="n">op</span><span class="o">.</span><span class="n">repeat</span><span class="p">(</span><span class="nb">range</span><span class="p">(</span><span class="mi">5</span><span class="p">),</span> <span class="mi">3</span><span class="p">)</span>
    <span class="k">print</span> <span class="s">'op._exposed_ ='</span><span class="p">,</span> <span class="n">op</span><span class="o">.</span><span class="n">_exposed_</span>

<span class="c">##</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">freeze_support</span><span class="p">()</span>
    <span class="n">test</span><span class="p">()</span>
</pre></div>
</div>
<p>Using <tt class="xref py py-class docutils literal"><span class="pre">Pool</span></tt>:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="c">#</span>
<span class="c"># A test of `multiprocessing.Pool` class</span>
<span class="c">#</span>
<span class="c"># Copyright (c) 2006-2008, R Oudkerk</span>
<span class="c"># All rights reserved.</span>
<span class="c">#</span>

<span class="kn">import</span> <span class="nn">multiprocessing</span>
<span class="kn">import</span> <span class="nn">time</span>
<span class="kn">import</span> <span class="nn">random</span>
<span class="kn">import</span> <span class="nn">sys</span>

<span class="c">#</span>
<span class="c"># Functions used by test code</span>
<span class="c">#</span>

<span class="k">def</span> <span class="nf">calculate</span><span class="p">(</span><span class="n">func</span><span class="p">,</span> <span class="n">args</span><span class="p">):</span>
    <span class="n">result</span> <span class="o">=</span> <span class="n">func</span><span class="p">(</span><span class="o">*</span><span class="n">args</span><span class="p">)</span>
    <span class="k">return</span> <span class="s">'</span><span class="si">%s</span><span class="s"> says that </span><span class="si">%s%s</span><span class="s"> = </span><span class="si">%s</span><span class="s">'</span> <span class="o">%</span> <span class="p">(</span>
        <span class="n">multiprocessing</span><span class="o">.</span><span class="n">current_process</span><span class="p">()</span><span class="o">.</span><span class="n">name</span><span class="p">,</span>
        <span class="n">func</span><span class="o">.</span><span class="n">__name__</span><span class="p">,</span> <span class="n">args</span><span class="p">,</span> <span class="n">result</span>
        <span class="p">)</span>

<span class="k">def</span> <span class="nf">calculatestar</span><span class="p">(</span><span class="n">args</span><span class="p">):</span>
    <span class="k">return</span> <span class="n">calculate</span><span class="p">(</span><span class="o">*</span><span class="n">args</span><span class="p">)</span>

<span class="k">def</span> <span class="nf">mul</span><span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">b</span><span class="p">):</span>
    <span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">(</span><span class="mf">0.5</span><span class="o">*</span><span class="n">random</span><span class="o">.</span><span class="n">random</span><span class="p">())</span>
    <span class="k">return</span> <span class="n">a</span> <span class="o">*</span> <span class="n">b</span>

<span class="k">def</span> <span class="nf">plus</span><span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">b</span><span class="p">):</span>
    <span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">(</span><span class="mf">0.5</span><span class="o">*</span><span class="n">random</span><span class="o">.</span><span class="n">random</span><span class="p">())</span>
    <span class="k">return</span> <span class="n">a</span> <span class="o">+</span> <span class="n">b</span>

<span class="k">def</span> <span class="nf">f</span><span class="p">(</span><span class="n">x</span><span class="p">):</span>
    <span class="k">return</span> <span class="mf">1.0</span> <span class="o">/</span> <span class="p">(</span><span class="n">x</span><span class="o">-</span><span class="mf">5.0</span><span class="p">)</span>

<span class="k">def</span> <span class="nf">pow3</span><span class="p">(</span><span class="n">x</span><span class="p">):</span>
    <span class="k">return</span> <span class="n">x</span><span class="o">**</span><span class="mi">3</span>

<span class="k">def</span> <span class="nf">noop</span><span class="p">(</span><span class="n">x</span><span class="p">):</span>
    <span class="k">pass</span>

<span class="c">#</span>
<span class="c"># Test code</span>
<span class="c">#</span>

<span class="k">def</span> <span class="nf">test</span><span class="p">():</span>
    <span class="k">print</span> <span class="s">'cpu_count() = </span><span class="si">%d</span><span class="se">\n</span><span class="s">'</span> <span class="o">%</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">cpu_count</span><span class="p">()</span>

    <span class="c">#</span>
    <span class="c"># Create pool</span>
    <span class="c">#</span>

    <span class="n">PROCESSES</span> <span class="o">=</span> <span class="mi">4</span>
    <span class="k">print</span> <span class="s">'Creating pool with </span><span class="si">%d</span><span class="s"> processes</span><span class="se">\n</span><span class="s">'</span> <span class="o">%</span> <span class="n">PROCESSES</span>
    <span class="n">pool</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Pool</span><span class="p">(</span><span class="n">PROCESSES</span><span class="p">)</span>
    <span class="k">print</span> <span class="s">'pool = </span><span class="si">%s</span><span class="s">'</span> <span class="o">%</span> <span class="n">pool</span>
    <span class="k">print</span>

    <span class="c">#</span>
    <span class="c"># Tests</span>
    <span class="c">#</span>

    <span class="n">TASKS</span> <span class="o">=</span> <span class="p">[(</span><span class="n">mul</span><span class="p">,</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="mi">7</span><span class="p">))</span> <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">)]</span> <span class="o">+</span> \
            <span class="p">[(</span><span class="n">plus</span><span class="p">,</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="mi">8</span><span class="p">))</span> <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">)]</span>

    <span class="n">results</span> <span class="o">=</span> <span class="p">[</span><span class="n">pool</span><span class="o">.</span><span class="n">apply_async</span><span class="p">(</span><span class="n">calculate</span><span class="p">,</span> <span class="n">t</span><span class="p">)</span> <span class="k">for</span> <span class="n">t</span> <span class="ow">in</span> <span class="n">TASKS</span><span class="p">]</span>
    <span class="n">imap_it</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">imap</span><span class="p">(</span><span class="n">calculatestar</span><span class="p">,</span> <span class="n">TASKS</span><span class="p">)</span>
    <span class="n">imap_unordered_it</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">imap_unordered</span><span class="p">(</span><span class="n">calculatestar</span><span class="p">,</span> <span class="n">TASKS</span><span class="p">)</span>

    <span class="k">print</span> <span class="s">'Ordered results using pool.apply_async():'</span>
    <span class="k">for</span> <span class="n">r</span> <span class="ow">in</span> <span class="n">results</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">'</span><span class="p">,</span> <span class="n">r</span><span class="o">.</span><span class="n">get</span><span class="p">()</span>
    <span class="k">print</span>

    <span class="k">print</span> <span class="s">'Ordered results using pool.imap():'</span>
    <span class="k">for</span> <span class="n">x</span> <span class="ow">in</span> <span class="n">imap_it</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">'</span><span class="p">,</span> <span class="n">x</span>
    <span class="k">print</span>

    <span class="k">print</span> <span class="s">'Unordered results using pool.imap_unordered():'</span>
    <span class="k">for</span> <span class="n">x</span> <span class="ow">in</span> <span class="n">imap_unordered_it</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">'</span><span class="p">,</span> <span class="n">x</span>
    <span class="k">print</span>

    <span class="k">print</span> <span class="s">'Ordered results using pool.map() --- will block till complete:'</span>
    <span class="k">for</span> <span class="n">x</span> <span class="ow">in</span> <span class="n">pool</span><span class="o">.</span><span class="n">map</span><span class="p">(</span><span class="n">calculatestar</span><span class="p">,</span> <span class="n">TASKS</span><span class="p">):</span>
        <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">'</span><span class="p">,</span> <span class="n">x</span>
    <span class="k">print</span>

    <span class="c">#</span>
    <span class="c"># Simple benchmarks</span>
    <span class="c">#</span>

    <span class="n">N</span> <span class="o">=</span> <span class="mi">100000</span>
    <span class="k">print</span> <span class="s">'def pow3(x): return x**3'</span>

    <span class="n">t</span> <span class="o">=</span> <span class="n">time</span><span class="o">.</span><span class="n">time</span><span class="p">()</span>
    <span class="n">A</span> <span class="o">=</span> <span class="nb">map</span><span class="p">(</span><span class="n">pow3</span><span class="p">,</span> <span class="nb">xrange</span><span class="p">(</span><span class="n">N</span><span class="p">))</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">map(pow3, xrange(</span><span class="si">%d</span><span class="s">)):</span><span class="se">\n\t\t</span><span class="si">%s</span><span class="s"> seconds'</span> <span class="o">%</span> \
          <span class="p">(</span><span class="n">N</span><span class="p">,</span> <span class="n">time</span><span class="o">.</span><span class="n">time</span><span class="p">()</span> <span class="o">-</span> <span class="n">t</span><span class="p">)</span>

    <span class="n">t</span> <span class="o">=</span> <span class="n">time</span><span class="o">.</span><span class="n">time</span><span class="p">()</span>
    <span class="n">B</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">map</span><span class="p">(</span><span class="n">pow3</span><span class="p">,</span> <span class="nb">xrange</span><span class="p">(</span><span class="n">N</span><span class="p">))</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">pool.map(pow3, xrange(</span><span class="si">%d</span><span class="s">)):</span><span class="se">\n\t\t</span><span class="si">%s</span><span class="s"> seconds'</span> <span class="o">%</span> \
          <span class="p">(</span><span class="n">N</span><span class="p">,</span> <span class="n">time</span><span class="o">.</span><span class="n">time</span><span class="p">()</span> <span class="o">-</span> <span class="n">t</span><span class="p">)</span>

    <span class="n">t</span> <span class="o">=</span> <span class="n">time</span><span class="o">.</span><span class="n">time</span><span class="p">()</span>
    <span class="n">C</span> <span class="o">=</span> <span class="nb">list</span><span class="p">(</span><span class="n">pool</span><span class="o">.</span><span class="n">imap</span><span class="p">(</span><span class="n">pow3</span><span class="p">,</span> <span class="nb">xrange</span><span class="p">(</span><span class="n">N</span><span class="p">),</span> <span class="n">chunksize</span><span class="o">=</span><span class="n">N</span><span class="o">//</span><span class="mi">8</span><span class="p">))</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">list(pool.imap(pow3, xrange(</span><span class="si">%d</span><span class="s">), chunksize=</span><span class="si">%d</span><span class="s">)):</span><span class="se">\n\t\t</span><span class="si">%s</span><span class="s">'</span> \
          <span class="s">' seconds'</span> <span class="o">%</span> <span class="p">(</span><span class="n">N</span><span class="p">,</span> <span class="n">N</span><span class="o">//</span><span class="mi">8</span><span class="p">,</span> <span class="n">time</span><span class="o">.</span><span class="n">time</span><span class="p">()</span> <span class="o">-</span> <span class="n">t</span><span class="p">)</span>

    <span class="k">assert</span> <span class="n">A</span> <span class="o">==</span> <span class="n">B</span> <span class="o">==</span> <span class="n">C</span><span class="p">,</span> <span class="p">(</span><span class="nb">len</span><span class="p">(</span><span class="n">A</span><span class="p">),</span> <span class="nb">len</span><span class="p">(</span><span class="n">B</span><span class="p">),</span> <span class="nb">len</span><span class="p">(</span><span class="n">C</span><span class="p">))</span>
    <span class="k">print</span>

    <span class="n">L</span> <span class="o">=</span> <span class="p">[</span><span class="bp">None</span><span class="p">]</span> <span class="o">*</span> <span class="mi">1000000</span>
    <span class="k">print</span> <span class="s">'def noop(x): pass'</span>
    <span class="k">print</span> <span class="s">'L = [None] * 1000000'</span>

    <span class="n">t</span> <span class="o">=</span> <span class="n">time</span><span class="o">.</span><span class="n">time</span><span class="p">()</span>
    <span class="n">A</span> <span class="o">=</span> <span class="nb">map</span><span class="p">(</span><span class="n">noop</span><span class="p">,</span> <span class="n">L</span><span class="p">)</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">map(noop, L):</span><span class="se">\n\t\t</span><span class="si">%s</span><span class="s"> seconds'</span> <span class="o">%</span> \
          <span class="p">(</span><span class="n">time</span><span class="o">.</span><span class="n">time</span><span class="p">()</span> <span class="o">-</span> <span class="n">t</span><span class="p">)</span>

    <span class="n">t</span> <span class="o">=</span> <span class="n">time</span><span class="o">.</span><span class="n">time</span><span class="p">()</span>
    <span class="n">B</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">map</span><span class="p">(</span><span class="n">noop</span><span class="p">,</span> <span class="n">L</span><span class="p">)</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">pool.map(noop, L):</span><span class="se">\n\t\t</span><span class="si">%s</span><span class="s"> seconds'</span> <span class="o">%</span> \
          <span class="p">(</span><span class="n">time</span><span class="o">.</span><span class="n">time</span><span class="p">()</span> <span class="o">-</span> <span class="n">t</span><span class="p">)</span>

    <span class="n">t</span> <span class="o">=</span> <span class="n">time</span><span class="o">.</span><span class="n">time</span><span class="p">()</span>
    <span class="n">C</span> <span class="o">=</span> <span class="nb">list</span><span class="p">(</span><span class="n">pool</span><span class="o">.</span><span class="n">imap</span><span class="p">(</span><span class="n">noop</span><span class="p">,</span> <span class="n">L</span><span class="p">,</span> <span class="n">chunksize</span><span class="o">=</span><span class="nb">len</span><span class="p">(</span><span class="n">L</span><span class="p">)</span><span class="o">//</span><span class="mi">8</span><span class="p">))</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">list(pool.imap(noop, L, chunksize=</span><span class="si">%d</span><span class="s">)):</span><span class="se">\n\t\t</span><span class="si">%s</span><span class="s"> seconds'</span> <span class="o">%</span> \
          <span class="p">(</span><span class="nb">len</span><span class="p">(</span><span class="n">L</span><span class="p">)</span><span class="o">//</span><span class="mi">8</span><span class="p">,</span> <span class="n">time</span><span class="o">.</span><span class="n">time</span><span class="p">()</span> <span class="o">-</span> <span class="n">t</span><span class="p">)</span>

    <span class="k">assert</span> <span class="n">A</span> <span class="o">==</span> <span class="n">B</span> <span class="o">==</span> <span class="n">C</span><span class="p">,</span> <span class="p">(</span><span class="nb">len</span><span class="p">(</span><span class="n">A</span><span class="p">),</span> <span class="nb">len</span><span class="p">(</span><span class="n">B</span><span class="p">),</span> <span class="nb">len</span><span class="p">(</span><span class="n">C</span><span class="p">))</span>
    <span class="k">print</span>

    <span class="k">del</span> <span class="n">A</span><span class="p">,</span> <span class="n">B</span><span class="p">,</span> <span class="n">C</span><span class="p">,</span> <span class="n">L</span>

    <span class="c">#</span>
    <span class="c"># Test error handling</span>
    <span class="c">#</span>

    <span class="k">print</span> <span class="s">'Testing error handling:'</span>

    <span class="k">try</span><span class="p">:</span>
        <span class="k">print</span> <span class="n">pool</span><span class="o">.</span><span class="n">apply</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="p">(</span><span class="mi">5</span><span class="p">,))</span>
    <span class="k">except</span> <span class="ne">ZeroDivisionError</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">Got ZeroDivisionError as expected from pool.apply()'</span>
    <span class="k">else</span><span class="p">:</span>
        <span class="k">raise</span> <span class="ne">AssertionError</span><span class="p">(</span><span class="s">'expected ZeroDivisionError'</span><span class="p">)</span>

    <span class="k">try</span><span class="p">:</span>
        <span class="k">print</span> <span class="n">pool</span><span class="o">.</span><span class="n">map</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">))</span>
    <span class="k">except</span> <span class="ne">ZeroDivisionError</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">Got ZeroDivisionError as expected from pool.map()'</span>
    <span class="k">else</span><span class="p">:</span>
        <span class="k">raise</span> <span class="ne">AssertionError</span><span class="p">(</span><span class="s">'expected ZeroDivisionError'</span><span class="p">)</span>

    <span class="k">try</span><span class="p">:</span>
        <span class="k">print</span> <span class="nb">list</span><span class="p">(</span><span class="n">pool</span><span class="o">.</span><span class="n">imap</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">)))</span>
    <span class="k">except</span> <span class="ne">ZeroDivisionError</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">Got ZeroDivisionError as expected from list(pool.imap())'</span>
    <span class="k">else</span><span class="p">:</span>
        <span class="k">raise</span> <span class="ne">AssertionError</span><span class="p">(</span><span class="s">'expected ZeroDivisionError'</span><span class="p">)</span>

    <span class="n">it</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">imap</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">))</span>
    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">):</span>
        <span class="k">try</span><span class="p">:</span>
            <span class="n">x</span> <span class="o">=</span> <span class="n">it</span><span class="o">.</span><span class="n">next</span><span class="p">()</span>
        <span class="k">except</span> <span class="ne">ZeroDivisionError</span><span class="p">:</span>
            <span class="k">if</span> <span class="n">i</span> <span class="o">==</span> <span class="mi">5</span><span class="p">:</span>
                <span class="k">pass</span>
        <span class="k">except</span> <span class="ne">StopIteration</span><span class="p">:</span>
            <span class="k">break</span>
        <span class="k">else</span><span class="p">:</span>
            <span class="k">if</span> <span class="n">i</span> <span class="o">==</span> <span class="mi">5</span><span class="p">:</span>
                <span class="k">raise</span> <span class="ne">AssertionError</span><span class="p">(</span><span class="s">'expected ZeroDivisionError'</span><span class="p">)</span>

    <span class="k">assert</span> <span class="n">i</span> <span class="o">==</span> <span class="mi">9</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">Got ZeroDivisionError as expected from IMapIterator.next()'</span>
    <span class="k">print</span>

    <span class="c">#</span>
    <span class="c"># Testing timeouts</span>
    <span class="c">#</span>

    <span class="k">print</span> <span class="s">'Testing ApplyResult.get() with timeout:'</span><span class="p">,</span>
    <span class="n">res</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">apply_async</span><span class="p">(</span><span class="n">calculate</span><span class="p">,</span> <span class="n">TASKS</span><span class="p">[</span><span class="mi">0</span><span class="p">])</span>
    <span class="k">while</span> <span class="mi">1</span><span class="p">:</span>
        <span class="n">sys</span><span class="o">.</span><span class="n">stdout</span><span class="o">.</span><span class="n">flush</span><span class="p">()</span>
        <span class="k">try</span><span class="p">:</span>
            <span class="n">sys</span><span class="o">.</span><span class="n">stdout</span><span class="o">.</span><span class="n">write</span><span class="p">(</span><span class="s">'</span><span class="se">\n\t</span><span class="si">%s</span><span class="s">'</span> <span class="o">%</span> <span class="n">res</span><span class="o">.</span><span class="n">get</span><span class="p">(</span><span class="mf">0.02</span><span class="p">))</span>
            <span class="k">break</span>
        <span class="k">except</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">TimeoutError</span><span class="p">:</span>
            <span class="n">sys</span><span class="o">.</span><span class="n">stdout</span><span class="o">.</span><span class="n">write</span><span class="p">(</span><span class="s">'.'</span><span class="p">)</span>
    <span class="k">print</span>
    <span class="k">print</span>

    <span class="k">print</span> <span class="s">'Testing IMapIterator.next() with timeout:'</span><span class="p">,</span>
    <span class="n">it</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">imap</span><span class="p">(</span><span class="n">calculatestar</span><span class="p">,</span> <span class="n">TASKS</span><span class="p">)</span>
    <span class="k">while</span> <span class="mi">1</span><span class="p">:</span>
        <span class="n">sys</span><span class="o">.</span><span class="n">stdout</span><span class="o">.</span><span class="n">flush</span><span class="p">()</span>
        <span class="k">try</span><span class="p">:</span>
            <span class="n">sys</span><span class="o">.</span><span class="n">stdout</span><span class="o">.</span><span class="n">write</span><span class="p">(</span><span class="s">'</span><span class="se">\n\t</span><span class="si">%s</span><span class="s">'</span> <span class="o">%</span> <span class="n">it</span><span class="o">.</span><span class="n">next</span><span class="p">(</span><span class="mf">0.02</span><span class="p">))</span>
        <span class="k">except</span> <span class="ne">StopIteration</span><span class="p">:</span>
            <span class="k">break</span>
        <span class="k">except</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">TimeoutError</span><span class="p">:</span>
            <span class="n">sys</span><span class="o">.</span><span class="n">stdout</span><span class="o">.</span><span class="n">write</span><span class="p">(</span><span class="s">'.'</span><span class="p">)</span>
    <span class="k">print</span>
    <span class="k">print</span>

    <span class="c">#</span>
    <span class="c"># Testing callback</span>
    <span class="c">#</span>

    <span class="k">print</span> <span class="s">'Testing callback:'</span>

    <span class="n">A</span> <span class="o">=</span> <span class="p">[]</span>
    <span class="n">B</span> <span class="o">=</span> <span class="p">[</span><span class="mi">56</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">8</span><span class="p">,</span> <span class="mi">27</span><span class="p">,</span> <span class="mi">64</span><span class="p">,</span> <span class="mi">125</span><span class="p">,</span> <span class="mi">216</span><span class="p">,</span> <span class="mi">343</span><span class="p">,</span> <span class="mi">512</span><span class="p">,</span> <span class="mi">729</span><span class="p">]</span>

    <span class="n">r</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">apply_async</span><span class="p">(</span><span class="n">mul</span><span class="p">,</span> <span class="p">(</span><span class="mi">7</span><span class="p">,</span> <span class="mi">8</span><span class="p">),</span> <span class="n">callback</span><span class="o">=</span><span class="n">A</span><span class="o">.</span><span class="n">append</span><span class="p">)</span>
    <span class="n">r</span><span class="o">.</span><span class="n">wait</span><span class="p">()</span>

    <span class="n">r</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">map_async</span><span class="p">(</span><span class="n">pow3</span><span class="p">,</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">),</span> <span class="n">callback</span><span class="o">=</span><span class="n">A</span><span class="o">.</span><span class="n">extend</span><span class="p">)</span>
    <span class="n">r</span><span class="o">.</span><span class="n">wait</span><span class="p">()</span>

    <span class="k">if</span> <span class="n">A</span> <span class="o">==</span> <span class="n">B</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">callbacks succeeded</span><span class="se">\n</span><span class="s">'</span>
    <span class="k">else</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">*** callbacks failed</span><span class="se">\n\t\t</span><span class="si">%s</span><span class="s"> != </span><span class="si">%s</span><span class="se">\n</span><span class="s">'</span> <span class="o">%</span> <span class="p">(</span><span class="n">A</span><span class="p">,</span> <span class="n">B</span><span class="p">)</span>

    <span class="c">#</span>
    <span class="c"># Check there are no outstanding tasks</span>
    <span class="c">#</span>

    <span class="k">assert</span> <span class="ow">not</span> <span class="n">pool</span><span class="o">.</span><span class="n">_cache</span><span class="p">,</span> <span class="s">'cache = </span><span class="si">%r</span><span class="s">'</span> <span class="o">%</span> <span class="n">pool</span><span class="o">.</span><span class="n">_cache</span>

    <span class="c">#</span>
    <span class="c"># Check close() methods</span>
    <span class="c">#</span>

    <span class="k">print</span> <span class="s">'Testing close():'</span>

    <span class="k">for</span> <span class="n">worker</span> <span class="ow">in</span> <span class="n">pool</span><span class="o">.</span><span class="n">_pool</span><span class="p">:</span>
        <span class="k">assert</span> <span class="n">worker</span><span class="o">.</span><span class="n">is_alive</span><span class="p">()</span>

    <span class="n">result</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">apply_async</span><span class="p">(</span><span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">,</span> <span class="p">[</span><span class="mf">0.5</span><span class="p">])</span>
    <span class="n">pool</span><span class="o">.</span><span class="n">close</span><span class="p">()</span>
    <span class="n">pool</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>

    <span class="k">assert</span> <span class="n">result</span><span class="o">.</span><span class="n">get</span><span class="p">()</span> <span class="ow">is</span> <span class="bp">None</span>

    <span class="k">for</span> <span class="n">worker</span> <span class="ow">in</span> <span class="n">pool</span><span class="o">.</span><span class="n">_pool</span><span class="p">:</span>
        <span class="k">assert</span> <span class="ow">not</span> <span class="n">worker</span><span class="o">.</span><span class="n">is_alive</span><span class="p">()</span>

    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">close() succeeded</span><span class="se">\n</span><span class="s">'</span>

    <span class="c">#</span>
    <span class="c"># Check terminate() method</span>
    <span class="c">#</span>

    <span class="k">print</span> <span class="s">'Testing terminate():'</span>

    <span class="n">pool</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Pool</span><span class="p">(</span><span class="mi">2</span><span class="p">)</span>
    <span class="n">DELTA</span> <span class="o">=</span> <span class="mf">0.1</span>
    <span class="n">ignore</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">apply</span><span class="p">(</span><span class="n">pow3</span><span class="p">,</span> <span class="p">[</span><span class="mi">2</span><span class="p">])</span>
    <span class="n">results</span> <span class="o">=</span> <span class="p">[</span><span class="n">pool</span><span class="o">.</span><span class="n">apply_async</span><span class="p">(</span><span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">,</span> <span class="p">[</span><span class="n">DELTA</span><span class="p">])</span> <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">100</span><span class="p">)]</span>
    <span class="n">pool</span><span class="o">.</span><span class="n">terminate</span><span class="p">()</span>
    <span class="n">pool</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>

    <span class="k">for</span> <span class="n">worker</span> <span class="ow">in</span> <span class="n">pool</span><span class="o">.</span><span class="n">_pool</span><span class="p">:</span>
        <span class="k">assert</span> <span class="ow">not</span> <span class="n">worker</span><span class="o">.</span><span class="n">is_alive</span><span class="p">()</span>

    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">terminate() succeeded</span><span class="se">\n</span><span class="s">'</span>

    <span class="c">#</span>
    <span class="c"># Check garbage collection</span>
    <span class="c">#</span>

    <span class="k">print</span> <span class="s">'Testing garbage collection:'</span>

    <span class="n">pool</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Pool</span><span class="p">(</span><span class="mi">2</span><span class="p">)</span>
    <span class="n">DELTA</span> <span class="o">=</span> <span class="mf">0.1</span>
    <span class="n">processes</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">_pool</span>
    <span class="n">ignore</span> <span class="o">=</span> <span class="n">pool</span><span class="o">.</span><span class="n">apply</span><span class="p">(</span><span class="n">pow3</span><span class="p">,</span> <span class="p">[</span><span class="mi">2</span><span class="p">])</span>
    <span class="n">results</span> <span class="o">=</span> <span class="p">[</span><span class="n">pool</span><span class="o">.</span><span class="n">apply_async</span><span class="p">(</span><span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">,</span> <span class="p">[</span><span class="n">DELTA</span><span class="p">])</span> <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">100</span><span class="p">)]</span>

    <span class="n">results</span> <span class="o">=</span> <span class="n">pool</span> <span class="o">=</span> <span class="bp">None</span>

    <span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">(</span><span class="n">DELTA</span> <span class="o">*</span> <span class="mi">2</span><span class="p">)</span>

    <span class="k">for</span> <span class="n">worker</span> <span class="ow">in</span> <span class="n">processes</span><span class="p">:</span>
        <span class="k">assert</span> <span class="ow">not</span> <span class="n">worker</span><span class="o">.</span><span class="n">is_alive</span><span class="p">()</span>

    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">garbage collection succeeded</span><span class="se">\n</span><span class="s">'</span>


<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">multiprocessing</span><span class="o">.</span><span class="n">freeze_support</span><span class="p">()</span>

    <span class="k">assert</span> <span class="nb">len</span><span class="p">(</span><span class="n">sys</span><span class="o">.</span><span class="n">argv</span><span class="p">)</span> <span class="ow">in</span> <span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="mi">2</span><span class="p">)</span>

    <span class="k">if</span> <span class="nb">len</span><span class="p">(</span><span class="n">sys</span><span class="o">.</span><span class="n">argv</span><span class="p">)</span> <span class="o">==</span> <span class="mi">1</span> <span class="ow">or</span> <span class="n">sys</span><span class="o">.</span><span class="n">argv</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">==</span> <span class="s">'processes'</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">' Using processes '</span><span class="o">.</span><span class="n">center</span><span class="p">(</span><span class="mi">79</span><span class="p">,</span> <span class="s">'-'</span><span class="p">)</span>
    <span class="k">elif</span> <span class="n">sys</span><span class="o">.</span><span class="n">argv</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">==</span> <span class="s">'threads'</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">' Using threads '</span><span class="o">.</span><span class="n">center</span><span class="p">(</span><span class="mi">79</span><span class="p">,</span> <span class="s">'-'</span><span class="p">)</span>
        <span class="kn">import</span> <span class="nn">multiprocessing.dummy</span> <span class="kn">as</span> <span class="nn">multiprocessing</span>
    <span class="k">else</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">'Usage:</span><span class="se">\n\t</span><span class="si">%s</span><span class="s"> [processes | threads]'</span> <span class="o">%</span> <span class="n">sys</span><span class="o">.</span><span class="n">argv</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span>
        <span class="k">raise</span> <span class="ne">SystemExit</span><span class="p">(</span><span class="mi">2</span><span class="p">)</span>

    <span class="n">test</span><span class="p">()</span>
</pre></div>
</div>
<p>Synchronization types like locks, conditions and queues:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="c">#</span>
<span class="c"># A test file for the `multiprocessing` package</span>
<span class="c">#</span>
<span class="c"># Copyright (c) 2006-2008, R Oudkerk</span>
<span class="c"># All rights reserved.</span>
<span class="c">#</span>

<span class="kn">import</span> <span class="nn">time</span><span class="o">,</span> <span class="nn">sys</span><span class="o">,</span> <span class="nn">random</span>
<span class="kn">from</span> <span class="nn">Queue</span> <span class="kn">import</span> <span class="n">Empty</span>

<span class="kn">import</span> <span class="nn">multiprocessing</span>               <span class="c"># may get overwritten</span>


<span class="c">#### TEST_VALUE</span>

<span class="k">def</span> <span class="nf">value_func</span><span class="p">(</span><span class="n">running</span><span class="p">,</span> <span class="n">mutex</span><span class="p">):</span>
    <span class="n">random</span><span class="o">.</span><span class="n">seed</span><span class="p">()</span>
    <span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">(</span><span class="n">random</span><span class="o">.</span><span class="n">random</span><span class="p">()</span><span class="o">*</span><span class="mi">4</span><span class="p">)</span>

    <span class="n">mutex</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t\t\t</span><span class="s">'</span> <span class="o">+</span> <span class="nb">str</span><span class="p">(</span><span class="n">multiprocessing</span><span class="o">.</span><span class="n">current_process</span><span class="p">())</span> <span class="o">+</span> <span class="s">' has finished'</span>
    <span class="n">running</span><span class="o">.</span><span class="n">value</span> <span class="o">-=</span> <span class="mi">1</span>
    <span class="n">mutex</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

<span class="k">def</span> <span class="nf">test_value</span><span class="p">():</span>
    <span class="n">TASKS</span> <span class="o">=</span> <span class="mi">10</span>
    <span class="n">running</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Value</span><span class="p">(</span><span class="s">'i'</span><span class="p">,</span> <span class="n">TASKS</span><span class="p">)</span>
    <span class="n">mutex</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Lock</span><span class="p">()</span>

    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="n">TASKS</span><span class="p">):</span>
        <span class="n">p</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">value_func</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">running</span><span class="p">,</span> <span class="n">mutex</span><span class="p">))</span>
        <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>

    <span class="k">while</span> <span class="n">running</span><span class="o">.</span><span class="n">value</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">:</span>
        <span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">(</span><span class="mf">0.08</span><span class="p">)</span>
        <span class="n">mutex</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
        <span class="k">print</span> <span class="n">running</span><span class="o">.</span><span class="n">value</span><span class="p">,</span>
        <span class="n">sys</span><span class="o">.</span><span class="n">stdout</span><span class="o">.</span><span class="n">flush</span><span class="p">()</span>
        <span class="n">mutex</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

    <span class="k">print</span>
    <span class="k">print</span> <span class="s">'No more running processes'</span>


<span class="c">#### TEST_QUEUE</span>

<span class="k">def</span> <span class="nf">queue_func</span><span class="p">(</span><span class="n">queue</span><span class="p">):</span>
    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">30</span><span class="p">):</span>
        <span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">(</span><span class="mf">0.5</span> <span class="o">*</span> <span class="n">random</span><span class="o">.</span><span class="n">random</span><span class="p">())</span>
        <span class="n">queue</span><span class="o">.</span><span class="n">put</span><span class="p">(</span><span class="n">i</span><span class="o">*</span><span class="n">i</span><span class="p">)</span>
    <span class="n">queue</span><span class="o">.</span><span class="n">put</span><span class="p">(</span><span class="s">'STOP'</span><span class="p">)</span>

<span class="k">def</span> <span class="nf">test_queue</span><span class="p">():</span>
    <span class="n">q</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Queue</span><span class="p">()</span>

    <span class="n">p</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">queue_func</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">q</span><span class="p">,))</span>
    <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>

    <span class="n">o</span> <span class="o">=</span> <span class="bp">None</span>
    <span class="k">while</span> <span class="n">o</span> <span class="o">!=</span> <span class="s">'STOP'</span><span class="p">:</span>
        <span class="k">try</span><span class="p">:</span>
            <span class="n">o</span> <span class="o">=</span> <span class="n">q</span><span class="o">.</span><span class="n">get</span><span class="p">(</span><span class="n">timeout</span><span class="o">=</span><span class="mf">0.3</span><span class="p">)</span>
            <span class="k">print</span> <span class="n">o</span><span class="p">,</span>
            <span class="n">sys</span><span class="o">.</span><span class="n">stdout</span><span class="o">.</span><span class="n">flush</span><span class="p">()</span>
        <span class="k">except</span> <span class="n">Empty</span><span class="p">:</span>
            <span class="k">print</span> <span class="s">'TIMEOUT'</span>

    <span class="k">print</span>


<span class="c">#### TEST_CONDITION</span>

<span class="k">def</span> <span class="nf">condition_func</span><span class="p">(</span><span class="n">cond</span><span class="p">):</span>
    <span class="n">cond</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">'</span> <span class="o">+</span> <span class="nb">str</span><span class="p">(</span><span class="n">cond</span><span class="p">)</span>
    <span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">(</span><span class="mi">2</span><span class="p">)</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">child is notifying'</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">'</span> <span class="o">+</span> <span class="nb">str</span><span class="p">(</span><span class="n">cond</span><span class="p">)</span>
    <span class="n">cond</span><span class="o">.</span><span class="n">notify</span><span class="p">()</span>
    <span class="n">cond</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

<span class="k">def</span> <span class="nf">test_condition</span><span class="p">():</span>
    <span class="n">cond</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Condition</span><span class="p">()</span>

    <span class="n">p</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">condition_func</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">cond</span><span class="p">,))</span>
    <span class="k">print</span> <span class="n">cond</span>

    <span class="n">cond</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
    <span class="k">print</span> <span class="n">cond</span>
    <span class="n">cond</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
    <span class="k">print</span> <span class="n">cond</span>

    <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>

    <span class="k">print</span> <span class="s">'main is waiting'</span>
    <span class="n">cond</span><span class="o">.</span><span class="n">wait</span><span class="p">()</span>
    <span class="k">print</span> <span class="s">'main has woken up'</span>

    <span class="k">print</span> <span class="n">cond</span>
    <span class="n">cond</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>
    <span class="k">print</span> <span class="n">cond</span>
    <span class="n">cond</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

    <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>
    <span class="k">print</span> <span class="n">cond</span>


<span class="c">#### TEST_SEMAPHORE</span>

<span class="k">def</span> <span class="nf">semaphore_func</span><span class="p">(</span><span class="n">sema</span><span class="p">,</span> <span class="n">mutex</span><span class="p">,</span> <span class="n">running</span><span class="p">):</span>
    <span class="n">sema</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>

    <span class="n">mutex</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
    <span class="n">running</span><span class="o">.</span><span class="n">value</span> <span class="o">+=</span> <span class="mi">1</span>
    <span class="k">print</span> <span class="n">running</span><span class="o">.</span><span class="n">value</span><span class="p">,</span> <span class="s">'tasks are running'</span>
    <span class="n">mutex</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

    <span class="n">random</span><span class="o">.</span><span class="n">seed</span><span class="p">()</span>
    <span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">(</span><span class="n">random</span><span class="o">.</span><span class="n">random</span><span class="p">()</span><span class="o">*</span><span class="mi">2</span><span class="p">)</span>

    <span class="n">mutex</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
    <span class="n">running</span><span class="o">.</span><span class="n">value</span> <span class="o">-=</span> <span class="mi">1</span>
    <span class="k">print</span> <span class="s">'</span><span class="si">%s</span><span class="s"> has finished'</span> <span class="o">%</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">current_process</span><span class="p">()</span>
    <span class="n">mutex</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

    <span class="n">sema</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

<span class="k">def</span> <span class="nf">test_semaphore</span><span class="p">():</span>
    <span class="n">sema</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Semaphore</span><span class="p">(</span><span class="mi">3</span><span class="p">)</span>
    <span class="n">mutex</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">RLock</span><span class="p">()</span>
    <span class="n">running</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Value</span><span class="p">(</span><span class="s">'i'</span><span class="p">,</span> <span class="mi">0</span><span class="p">)</span>

    <span class="n">processes</span> <span class="o">=</span> <span class="p">[</span>
        <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">semaphore_func</span><span class="p">,</span>
                                <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">sema</span><span class="p">,</span> <span class="n">mutex</span><span class="p">,</span> <span class="n">running</span><span class="p">))</span>
        <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">)</span>
        <span class="p">]</span>

    <span class="k">for</span> <span class="n">p</span> <span class="ow">in</span> <span class="n">processes</span><span class="p">:</span>
        <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>

    <span class="k">for</span> <span class="n">p</span> <span class="ow">in</span> <span class="n">processes</span><span class="p">:</span>
        <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>


<span class="c">#### TEST_JOIN_TIMEOUT</span>

<span class="k">def</span> <span class="nf">join_timeout_func</span><span class="p">():</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">child sleeping'</span>
    <span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">(</span><span class="mf">5.5</span><span class="p">)</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">child terminating'</span>

<span class="k">def</span> <span class="nf">test_join_timeout</span><span class="p">():</span>
    <span class="n">p</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">join_timeout_func</span><span class="p">)</span>
    <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>

    <span class="k">print</span> <span class="s">'waiting for process to finish'</span>

    <span class="k">while</span> <span class="mi">1</span><span class="p">:</span>
        <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">(</span><span class="n">timeout</span><span class="o">=</span><span class="mi">1</span><span class="p">)</span>
        <span class="k">if</span> <span class="ow">not</span> <span class="n">p</span><span class="o">.</span><span class="n">is_alive</span><span class="p">():</span>
            <span class="k">break</span>
        <span class="k">print</span> <span class="s">'.'</span><span class="p">,</span>
        <span class="n">sys</span><span class="o">.</span><span class="n">stdout</span><span class="o">.</span><span class="n">flush</span><span class="p">()</span>


<span class="c">#### TEST_EVENT</span>

<span class="k">def</span> <span class="nf">event_func</span><span class="p">(</span><span class="n">event</span><span class="p">):</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="si">%r</span><span class="s"> is waiting'</span> <span class="o">%</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">current_process</span><span class="p">()</span>
    <span class="n">event</span><span class="o">.</span><span class="n">wait</span><span class="p">()</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="si">%r</span><span class="s"> has woken up'</span> <span class="o">%</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">current_process</span><span class="p">()</span>

<span class="k">def</span> <span class="nf">test_event</span><span class="p">():</span>
    <span class="n">event</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Event</span><span class="p">()</span>

    <span class="n">processes</span> <span class="o">=</span> <span class="p">[</span><span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">event_func</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">event</span><span class="p">,))</span>
                 <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">5</span><span class="p">)]</span>

    <span class="k">for</span> <span class="n">p</span> <span class="ow">in</span> <span class="n">processes</span><span class="p">:</span>
        <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>

    <span class="k">print</span> <span class="s">'main is sleeping'</span>
    <span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">(</span><span class="mi">2</span><span class="p">)</span>

    <span class="k">print</span> <span class="s">'main is setting event'</span>
    <span class="n">event</span><span class="o">.</span><span class="n">set</span><span class="p">()</span>

    <span class="k">for</span> <span class="n">p</span> <span class="ow">in</span> <span class="n">processes</span><span class="p">:</span>
        <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>


<span class="c">#### TEST_SHAREDVALUES</span>

<span class="k">def</span> <span class="nf">sharedvalues_func</span><span class="p">(</span><span class="n">values</span><span class="p">,</span> <span class="n">arrays</span><span class="p">,</span> <span class="n">shared_values</span><span class="p">,</span> <span class="n">shared_arrays</span><span class="p">):</span>
    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="nb">len</span><span class="p">(</span><span class="n">values</span><span class="p">)):</span>
        <span class="n">v</span> <span class="o">=</span> <span class="n">values</span><span class="p">[</span><span class="n">i</span><span class="p">][</span><span class="mi">1</span><span class="p">]</span>
        <span class="n">sv</span> <span class="o">=</span> <span class="n">shared_values</span><span class="p">[</span><span class="n">i</span><span class="p">]</span><span class="o">.</span><span class="n">value</span>
        <span class="k">assert</span> <span class="n">v</span> <span class="o">==</span> <span class="n">sv</span>

    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="nb">len</span><span class="p">(</span><span class="n">values</span><span class="p">)):</span>
        <span class="n">a</span> <span class="o">=</span> <span class="n">arrays</span><span class="p">[</span><span class="n">i</span><span class="p">][</span><span class="mi">1</span><span class="p">]</span>
        <span class="n">sa</span> <span class="o">=</span> <span class="nb">list</span><span class="p">(</span><span class="n">shared_arrays</span><span class="p">[</span><span class="n">i</span><span class="p">][:])</span>
        <span class="k">assert</span> <span class="n">a</span> <span class="o">==</span> <span class="n">sa</span>

    <span class="k">print</span> <span class="s">'Tests passed'</span>

<span class="k">def</span> <span class="nf">test_sharedvalues</span><span class="p">():</span>
    <span class="n">values</span> <span class="o">=</span> <span class="p">[</span>
        <span class="p">(</span><span class="s">'i'</span><span class="p">,</span> <span class="mi">10</span><span class="p">),</span>
        <span class="p">(</span><span class="s">'h'</span><span class="p">,</span> <span class="o">-</span><span class="mi">2</span><span class="p">),</span>
        <span class="p">(</span><span class="s">'d'</span><span class="p">,</span> <span class="mf">1.25</span><span class="p">)</span>
        <span class="p">]</span>
    <span class="n">arrays</span> <span class="o">=</span> <span class="p">[</span>
        <span class="p">(</span><span class="s">'i'</span><span class="p">,</span> <span class="nb">range</span><span class="p">(</span><span class="mi">100</span><span class="p">)),</span>
        <span class="p">(</span><span class="s">'d'</span><span class="p">,</span> <span class="p">[</span><span class="mf">0.25</span> <span class="o">*</span> <span class="n">i</span> <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">100</span><span class="p">)]),</span>
        <span class="p">(</span><span class="s">'H'</span><span class="p">,</span> <span class="nb">range</span><span class="p">(</span><span class="mi">1000</span><span class="p">))</span>
        <span class="p">]</span>

    <span class="n">shared_values</span> <span class="o">=</span> <span class="p">[</span><span class="n">multiprocessing</span><span class="o">.</span><span class="n">Value</span><span class="p">(</span><span class="nb">id</span><span class="p">,</span> <span class="n">v</span><span class="p">)</span> <span class="k">for</span> <span class="nb">id</span><span class="p">,</span> <span class="n">v</span> <span class="ow">in</span> <span class="n">values</span><span class="p">]</span>
    <span class="n">shared_arrays</span> <span class="o">=</span> <span class="p">[</span><span class="n">multiprocessing</span><span class="o">.</span><span class="n">Array</span><span class="p">(</span><span class="nb">id</span><span class="p">,</span> <span class="n">a</span><span class="p">)</span> <span class="k">for</span> <span class="nb">id</span><span class="p">,</span> <span class="n">a</span> <span class="ow">in</span> <span class="n">arrays</span><span class="p">]</span>

    <span class="n">p</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span><span class="p">(</span>
        <span class="n">target</span><span class="o">=</span><span class="n">sharedvalues_func</span><span class="p">,</span>
        <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">values</span><span class="p">,</span> <span class="n">arrays</span><span class="p">,</span> <span class="n">shared_values</span><span class="p">,</span> <span class="n">shared_arrays</span><span class="p">)</span>
        <span class="p">)</span>
    <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
    <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>

    <span class="k">assert</span> <span class="n">p</span><span class="o">.</span><span class="n">exitcode</span> <span class="o">==</span> <span class="mi">0</span>


<span class="c">####</span>

<span class="k">def</span> <span class="nf">test</span><span class="p">(</span><span class="n">namespace</span><span class="o">=</span><span class="n">multiprocessing</span><span class="p">):</span>
    <span class="k">global</span> <span class="n">multiprocessing</span>

    <span class="n">multiprocessing</span> <span class="o">=</span> <span class="n">namespace</span>

    <span class="k">for</span> <span class="n">func</span> <span class="ow">in</span> <span class="p">[</span> <span class="n">test_value</span><span class="p">,</span> <span class="n">test_queue</span><span class="p">,</span> <span class="n">test_condition</span><span class="p">,</span>
                  <span class="n">test_semaphore</span><span class="p">,</span> <span class="n">test_join_timeout</span><span class="p">,</span> <span class="n">test_event</span><span class="p">,</span>
                  <span class="n">test_sharedvalues</span> <span class="p">]:</span>

        <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## </span><span class="si">%s</span><span class="se">\n</span><span class="s">'</span> <span class="o">%</span> <span class="n">func</span><span class="o">.</span><span class="n">__name__</span>
        <span class="n">func</span><span class="p">()</span>

    <span class="n">ignore</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">active_children</span><span class="p">()</span>      <span class="c"># cleanup any old processes</span>
    <span class="k">if</span> <span class="nb">hasattr</span><span class="p">(</span><span class="n">multiprocessing</span><span class="p">,</span> <span class="s">'_debug_info'</span><span class="p">):</span>
        <span class="n">info</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">_debug_info</span><span class="p">()</span>
        <span class="k">if</span> <span class="n">info</span><span class="p">:</span>
            <span class="k">print</span> <span class="n">info</span>
            <span class="k">raise</span> <span class="ne">ValueError</span><span class="p">(</span><span class="s">'there should be no positive refcounts left'</span><span class="p">)</span>


<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">multiprocessing</span><span class="o">.</span><span class="n">freeze_support</span><span class="p">()</span>

    <span class="k">assert</span> <span class="nb">len</span><span class="p">(</span><span class="n">sys</span><span class="o">.</span><span class="n">argv</span><span class="p">)</span> <span class="ow">in</span> <span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="mi">2</span><span class="p">)</span>

    <span class="k">if</span> <span class="nb">len</span><span class="p">(</span><span class="n">sys</span><span class="o">.</span><span class="n">argv</span><span class="p">)</span> <span class="o">==</span> <span class="mi">1</span> <span class="ow">or</span> <span class="n">sys</span><span class="o">.</span><span class="n">argv</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">==</span> <span class="s">'processes'</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">' Using processes '</span><span class="o">.</span><span class="n">center</span><span class="p">(</span><span class="mi">79</span><span class="p">,</span> <span class="s">'-'</span><span class="p">)</span>
        <span class="n">namespace</span> <span class="o">=</span> <span class="n">multiprocessing</span>
    <span class="k">elif</span> <span class="n">sys</span><span class="o">.</span><span class="n">argv</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">==</span> <span class="s">'manager'</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">' Using processes and a manager '</span><span class="o">.</span><span class="n">center</span><span class="p">(</span><span class="mi">79</span><span class="p">,</span> <span class="s">'-'</span><span class="p">)</span>
        <span class="n">namespace</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Manager</span><span class="p">()</span>
        <span class="n">namespace</span><span class="o">.</span><span class="n">Process</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span>
        <span class="n">namespace</span><span class="o">.</span><span class="n">current_process</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">current_process</span>
        <span class="n">namespace</span><span class="o">.</span><span class="n">active_children</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">active_children</span>
    <span class="k">elif</span> <span class="n">sys</span><span class="o">.</span><span class="n">argv</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">==</span> <span class="s">'threads'</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">' Using threads '</span><span class="o">.</span><span class="n">center</span><span class="p">(</span><span class="mi">79</span><span class="p">,</span> <span class="s">'-'</span><span class="p">)</span>
        <span class="kn">import</span> <span class="nn">multiprocessing.dummy</span> <span class="kn">as</span> <span class="nn">namespace</span>
    <span class="k">else</span><span class="p">:</span>
        <span class="k">print</span> <span class="s">'Usage:</span><span class="se">\n\t</span><span class="si">%s</span><span class="s"> [processes | manager | threads]'</span> <span class="o">%</span> <span class="n">sys</span><span class="o">.</span><span class="n">argv</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span>
        <span class="k">raise</span> <span class="ne">SystemExit</span><span class="p">(</span><span class="mi">2</span><span class="p">)</span>

    <span class="n">test</span><span class="p">(</span><span class="n">namespace</span><span class="p">)</span>
</pre></div>
</div>
<p>An example showing how to use queues to feed tasks to a collection of worker
processes and collect the results:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="c">#</span>
<span class="c"># Simple example which uses a pool of workers to carry out some tasks.</span>
<span class="c">#</span>
<span class="c"># Notice that the results will probably not come out of the output</span>
<span class="c"># queue in the same in the same order as the corresponding tasks were</span>
<span class="c"># put on the input queue.  If it is important to get the results back</span>
<span class="c"># in the original order then consider using `Pool.map()` or</span>
<span class="c"># `Pool.imap()` (which will save on the amount of code needed anyway).</span>
<span class="c">#</span>
<span class="c"># Copyright (c) 2006-2008, R Oudkerk</span>
<span class="c"># All rights reserved.</span>
<span class="c">#</span>

<span class="kn">import</span> <span class="nn">time</span>
<span class="kn">import</span> <span class="nn">random</span>

<span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">Queue</span><span class="p">,</span> <span class="n">current_process</span><span class="p">,</span> <span class="n">freeze_support</span>

<span class="c">#</span>
<span class="c"># Function run by worker processes</span>
<span class="c">#</span>

<span class="k">def</span> <span class="nf">worker</span><span class="p">(</span><span class="nb">input</span><span class="p">,</span> <span class="n">output</span><span class="p">):</span>
    <span class="k">for</span> <span class="n">func</span><span class="p">,</span> <span class="n">args</span> <span class="ow">in</span> <span class="nb">iter</span><span class="p">(</span><span class="nb">input</span><span class="o">.</span><span class="n">get</span><span class="p">,</span> <span class="s">'STOP'</span><span class="p">):</span>
        <span class="n">result</span> <span class="o">=</span> <span class="n">calculate</span><span class="p">(</span><span class="n">func</span><span class="p">,</span> <span class="n">args</span><span class="p">)</span>
        <span class="n">output</span><span class="o">.</span><span class="n">put</span><span class="p">(</span><span class="n">result</span><span class="p">)</span>

<span class="c">#</span>
<span class="c"># Function used to calculate result</span>
<span class="c">#</span>

<span class="k">def</span> <span class="nf">calculate</span><span class="p">(</span><span class="n">func</span><span class="p">,</span> <span class="n">args</span><span class="p">):</span>
    <span class="n">result</span> <span class="o">=</span> <span class="n">func</span><span class="p">(</span><span class="o">*</span><span class="n">args</span><span class="p">)</span>
    <span class="k">return</span> <span class="s">'</span><span class="si">%s</span><span class="s"> says that </span><span class="si">%s%s</span><span class="s"> = </span><span class="si">%s</span><span class="s">'</span> <span class="o">%</span> \
        <span class="p">(</span><span class="n">current_process</span><span class="p">()</span><span class="o">.</span><span class="n">name</span><span class="p">,</span> <span class="n">func</span><span class="o">.</span><span class="n">__name__</span><span class="p">,</span> <span class="n">args</span><span class="p">,</span> <span class="n">result</span><span class="p">)</span>

<span class="c">#</span>
<span class="c"># Functions referenced by tasks</span>
<span class="c">#</span>

<span class="k">def</span> <span class="nf">mul</span><span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">b</span><span class="p">):</span>
    <span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">(</span><span class="mf">0.5</span><span class="o">*</span><span class="n">random</span><span class="o">.</span><span class="n">random</span><span class="p">())</span>
    <span class="k">return</span> <span class="n">a</span> <span class="o">*</span> <span class="n">b</span>

<span class="k">def</span> <span class="nf">plus</span><span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">b</span><span class="p">):</span>
    <span class="n">time</span><span class="o">.</span><span class="n">sleep</span><span class="p">(</span><span class="mf">0.5</span><span class="o">*</span><span class="n">random</span><span class="o">.</span><span class="n">random</span><span class="p">())</span>
    <span class="k">return</span> <span class="n">a</span> <span class="o">+</span> <span class="n">b</span>

<span class="c">#</span>
<span class="c">#</span>
<span class="c">#</span>

<span class="k">def</span> <span class="nf">test</span><span class="p">():</span>
    <span class="n">NUMBER_OF_PROCESSES</span> <span class="o">=</span> <span class="mi">4</span>
    <span class="n">TASKS1</span> <span class="o">=</span> <span class="p">[(</span><span class="n">mul</span><span class="p">,</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="mi">7</span><span class="p">))</span> <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">20</span><span class="p">)]</span>
    <span class="n">TASKS2</span> <span class="o">=</span> <span class="p">[(</span><span class="n">plus</span><span class="p">,</span> <span class="p">(</span><span class="n">i</span><span class="p">,</span> <span class="mi">8</span><span class="p">))</span> <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">)]</span>

    <span class="c"># Create queues</span>
    <span class="n">task_queue</span> <span class="o">=</span> <span class="n">Queue</span><span class="p">()</span>
    <span class="n">done_queue</span> <span class="o">=</span> <span class="n">Queue</span><span class="p">()</span>

    <span class="c"># Submit tasks</span>
    <span class="k">for</span> <span class="n">task</span> <span class="ow">in</span> <span class="n">TASKS1</span><span class="p">:</span>
        <span class="n">task_queue</span><span class="o">.</span><span class="n">put</span><span class="p">(</span><span class="n">task</span><span class="p">)</span>

    <span class="c"># Start worker processes</span>
    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="n">NUMBER_OF_PROCESSES</span><span class="p">):</span>
        <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">worker</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">task_queue</span><span class="p">,</span> <span class="n">done_queue</span><span class="p">))</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>

    <span class="c"># Get and print results</span>
    <span class="k">print</span> <span class="s">'Unordered results:'</span>
    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="nb">len</span><span class="p">(</span><span class="n">TASKS1</span><span class="p">)):</span>
        <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">'</span><span class="p">,</span> <span class="n">done_queue</span><span class="o">.</span><span class="n">get</span><span class="p">()</span>

    <span class="c"># Add more tasks using `put()`</span>
    <span class="k">for</span> <span class="n">task</span> <span class="ow">in</span> <span class="n">TASKS2</span><span class="p">:</span>
        <span class="n">task_queue</span><span class="o">.</span><span class="n">put</span><span class="p">(</span><span class="n">task</span><span class="p">)</span>

    <span class="c"># Get and print some more results</span>
    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="nb">len</span><span class="p">(</span><span class="n">TASKS2</span><span class="p">)):</span>
        <span class="k">print</span> <span class="s">'</span><span class="se">\t</span><span class="s">'</span><span class="p">,</span> <span class="n">done_queue</span><span class="o">.</span><span class="n">get</span><span class="p">()</span>

    <span class="c"># Tell child processes to stop</span>
    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="n">NUMBER_OF_PROCESSES</span><span class="p">):</span>
        <span class="n">task_queue</span><span class="o">.</span><span class="n">put</span><span class="p">(</span><span class="s">'STOP'</span><span class="p">)</span>


<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">freeze_support</span><span class="p">()</span>
    <span class="n">test</span><span class="p">()</span>
</pre></div>
</div>
<p>An example of how a pool of worker processes can each run a
<tt class="xref py py-class docutils literal"><span class="pre">SimpleHTTPServer.HttpServer</span></tt> instance while sharing a single listening
socket.</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="c">#</span>
<span class="c"># Example where a pool of http servers share a single listening socket</span>
<span class="c">#</span>
<span class="c"># On Windows this module depends on the ability to pickle a socket</span>
<span class="c"># object so that the worker processes can inherit a copy of the server</span>
<span class="c"># object.  (We import `multiprocessing.reduction` to enable this pickling.)</span>
<span class="c">#</span>
<span class="c"># Not sure if we should synchronize access to `socket.accept()` method by</span>
<span class="c"># using a process-shared lock -- does not seem to be necessary.</span>
<span class="c">#</span>
<span class="c"># Copyright (c) 2006-2008, R Oudkerk</span>
<span class="c"># All rights reserved.</span>
<span class="c">#</span>

<span class="kn">import</span> <span class="nn">os</span>
<span class="kn">import</span> <span class="nn">sys</span>

<span class="kn">from</span> <span class="nn">multiprocessing</span> <span class="kn">import</span> <span class="n">Process</span><span class="p">,</span> <span class="n">current_process</span><span class="p">,</span> <span class="n">freeze_support</span>
<span class="kn">from</span> <span class="nn">BaseHTTPServer</span> <span class="kn">import</span> <span class="n">HTTPServer</span>
<span class="kn">from</span> <span class="nn">SimpleHTTPServer</span> <span class="kn">import</span> <span class="n">SimpleHTTPRequestHandler</span>

<span class="k">if</span> <span class="n">sys</span><span class="o">.</span><span class="n">platform</span> <span class="o">==</span> <span class="s">'win32'</span><span class="p">:</span>
    <span class="kn">import</span> <span class="nn">multiprocessing.reduction</span>    <span class="c"># make sockets pickable/inheritable</span>


<span class="k">def</span> <span class="nf">note</span><span class="p">(</span><span class="n">format</span><span class="p">,</span> <span class="o">*</span><span class="n">args</span><span class="p">):</span>
    <span class="n">sys</span><span class="o">.</span><span class="n">stderr</span><span class="o">.</span><span class="n">write</span><span class="p">(</span><span class="s">'[</span><span class="si">%s</span><span class="s">]</span><span class="se">\t</span><span class="si">%s</span><span class="se">\n</span><span class="s">'</span> <span class="o">%</span> <span class="p">(</span><span class="n">current_process</span><span class="p">()</span><span class="o">.</span><span class="n">name</span><span class="p">,</span> <span class="n">format</span><span class="o">%</span><span class="n">args</span><span class="p">))</span>


<span class="k">class</span> <span class="nc">RequestHandler</span><span class="p">(</span><span class="n">SimpleHTTPRequestHandler</span><span class="p">):</span>
    <span class="c"># we override log_message() to show which process is handling the request</span>
    <span class="k">def</span> <span class="nf">log_message</span><span class="p">(</span><span class="bp">self</span><span class="p">,</span> <span class="n">format</span><span class="p">,</span> <span class="o">*</span><span class="n">args</span><span class="p">):</span>
        <span class="n">note</span><span class="p">(</span><span class="n">format</span><span class="p">,</span> <span class="o">*</span><span class="n">args</span><span class="p">)</span>

<span class="k">def</span> <span class="nf">serve_forever</span><span class="p">(</span><span class="n">server</span><span class="p">):</span>
    <span class="n">note</span><span class="p">(</span><span class="s">'starting server'</span><span class="p">)</span>
    <span class="k">try</span><span class="p">:</span>
        <span class="n">server</span><span class="o">.</span><span class="n">serve_forever</span><span class="p">()</span>
    <span class="k">except</span> <span class="ne">KeyboardInterrupt</span><span class="p">:</span>
        <span class="k">pass</span>


<span class="k">def</span> <span class="nf">runpool</span><span class="p">(</span><span class="n">address</span><span class="p">,</span> <span class="n">number_of_processes</span><span class="p">):</span>
    <span class="c"># create a single server object -- children will each inherit a copy</span>
    <span class="n">server</span> <span class="o">=</span> <span class="n">HTTPServer</span><span class="p">(</span><span class="n">address</span><span class="p">,</span> <span class="n">RequestHandler</span><span class="p">)</span>

    <span class="c"># create child processes to act as workers</span>
    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">range</span><span class="p">(</span><span class="n">number_of_processes</span><span class="o">-</span><span class="mi">1</span><span class="p">):</span>
        <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">serve_forever</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">server</span><span class="p">,))</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>

    <span class="c"># main process also acts as a worker</span>
    <span class="n">serve_forever</span><span class="p">(</span><span class="n">server</span><span class="p">)</span>


<span class="k">def</span> <span class="nf">test</span><span class="p">():</span>
    <span class="n">DIR</span> <span class="o">=</span> <span class="n">os</span><span class="o">.</span><span class="n">path</span><span class="o">.</span><span class="n">join</span><span class="p">(</span><span class="n">os</span><span class="o">.</span><span class="n">path</span><span class="o">.</span><span class="n">dirname</span><span class="p">(</span><span class="n">__file__</span><span class="p">),</span> <span class="s">'..'</span><span class="p">)</span>
    <span class="n">ADDRESS</span> <span class="o">=</span> <span class="p">(</span><span class="s">'localhost'</span><span class="p">,</span> <span class="mi">8000</span><span class="p">)</span>
    <span class="n">NUMBER_OF_PROCESSES</span> <span class="o">=</span> <span class="mi">4</span>

    <span class="k">print</span> <span class="s">'Serving at http://</span><span class="si">%s</span><span class="s">:</span><span class="si">%d</span><span class="s"> using </span><span class="si">%d</span><span class="s"> worker processes'</span> <span class="o">%</span> \
          <span class="p">(</span><span class="n">ADDRESS</span><span class="p">[</span><span class="mi">0</span><span class="p">],</span> <span class="n">ADDRESS</span><span class="p">[</span><span class="mi">1</span><span class="p">],</span> <span class="n">NUMBER_OF_PROCESSES</span><span class="p">)</span>
    <span class="k">print</span> <span class="s">'To exit press Ctrl-'</span> <span class="o">+</span> <span class="p">[</span><span class="s">'C'</span><span class="p">,</span> <span class="s">'Break'</span><span class="p">][</span><span class="n">sys</span><span class="o">.</span><span class="n">platform</span><span class="o">==</span><span class="s">'win32'</span><span class="p">]</span>

    <span class="n">os</span><span class="o">.</span><span class="n">chdir</span><span class="p">(</span><span class="n">DIR</span><span class="p">)</span>
    <span class="n">runpool</span><span class="p">(</span><span class="n">ADDRESS</span><span class="p">,</span> <span class="n">NUMBER_OF_PROCESSES</span><span class="p">)</span>


<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">freeze_support</span><span class="p">()</span>
    <span class="n">test</span><span class="p">()</span>
</pre></div>
</div>
<p>Some simple benchmarks comparing <a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing" title="multiprocessing: Process-based &quot;threading&quot; interface."><tt class="xref py py-mod docutils literal"><span class="pre">multiprocessing</span></tt></a> with <a class="reference internal" href="http://docs.python.org/2/library/threading.html#module-threading" title="threading: Higher-level threading interface."><tt class="xref py py-mod docutils literal"><span class="pre">threading</span></tt></a>:</p>
<div class="highlight-python" style="position: relative;"><div class="highlight"><pre><span class="c">#</span>
<span class="c"># Simple benchmarks for the multiprocessing package</span>
<span class="c">#</span>
<span class="c"># Copyright (c) 2006-2008, R Oudkerk</span>
<span class="c"># All rights reserved.</span>
<span class="c">#</span>

<span class="kn">import</span> <span class="nn">time</span><span class="o">,</span> <span class="nn">sys</span><span class="o">,</span> <span class="nn">multiprocessing</span><span class="o">,</span> <span class="nn">threading</span><span class="o">,</span> <span class="nn">Queue</span><span class="o">,</span> <span class="nn">gc</span>

<span class="k">if</span> <span class="n">sys</span><span class="o">.</span><span class="n">platform</span> <span class="o">==</span> <span class="s">'win32'</span><span class="p">:</span>
    <span class="n">_timer</span> <span class="o">=</span> <span class="n">time</span><span class="o">.</span><span class="n">clock</span>
<span class="k">else</span><span class="p">:</span>
    <span class="n">_timer</span> <span class="o">=</span> <span class="n">time</span><span class="o">.</span><span class="n">time</span>

<span class="n">delta</span> <span class="o">=</span> <span class="mi">1</span>


<span class="c">#### TEST_QUEUESPEED</span>

<span class="k">def</span> <span class="nf">queuespeed_func</span><span class="p">(</span><span class="n">q</span><span class="p">,</span> <span class="n">c</span><span class="p">,</span> <span class="n">iterations</span><span class="p">):</span>
    <span class="n">a</span> <span class="o">=</span> <span class="s">'0'</span> <span class="o">*</span> <span class="mi">256</span>
    <span class="n">c</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
    <span class="n">c</span><span class="o">.</span><span class="n">notify</span><span class="p">()</span>
    <span class="n">c</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">xrange</span><span class="p">(</span><span class="n">iterations</span><span class="p">):</span>
        <span class="n">q</span><span class="o">.</span><span class="n">put</span><span class="p">(</span><span class="n">a</span><span class="p">)</span>

    <span class="n">q</span><span class="o">.</span><span class="n">put</span><span class="p">(</span><span class="s">'STOP'</span><span class="p">)</span>

<span class="k">def</span> <span class="nf">test_queuespeed</span><span class="p">(</span><span class="n">Process</span><span class="p">,</span> <span class="n">q</span><span class="p">,</span> <span class="n">c</span><span class="p">):</span>
    <span class="n">elapsed</span> <span class="o">=</span> <span class="mi">0</span>
    <span class="n">iterations</span> <span class="o">=</span> <span class="mi">1</span>

    <span class="k">while</span> <span class="n">elapsed</span> <span class="o">&lt;</span> <span class="n">delta</span><span class="p">:</span>
        <span class="n">iterations</span> <span class="o">*=</span> <span class="mi">2</span>

        <span class="n">p</span> <span class="o">=</span> <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">queuespeed_func</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">q</span><span class="p">,</span> <span class="n">c</span><span class="p">,</span> <span class="n">iterations</span><span class="p">))</span>
        <span class="n">c</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
        <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
        <span class="n">c</span><span class="o">.</span><span class="n">wait</span><span class="p">()</span>
        <span class="n">c</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

        <span class="n">result</span> <span class="o">=</span> <span class="bp">None</span>
        <span class="n">t</span> <span class="o">=</span> <span class="n">_timer</span><span class="p">()</span>

        <span class="k">while</span> <span class="n">result</span> <span class="o">!=</span> <span class="s">'STOP'</span><span class="p">:</span>
            <span class="n">result</span> <span class="o">=</span> <span class="n">q</span><span class="o">.</span><span class="n">get</span><span class="p">()</span>

        <span class="n">elapsed</span> <span class="o">=</span> <span class="n">_timer</span><span class="p">()</span> <span class="o">-</span> <span class="n">t</span>

        <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>

    <span class="k">print</span> <span class="n">iterations</span><span class="p">,</span> <span class="s">'objects passed through the queue in'</span><span class="p">,</span> <span class="n">elapsed</span><span class="p">,</span> <span class="s">'seconds'</span>
    <span class="k">print</span> <span class="s">'average number/sec:'</span><span class="p">,</span> <span class="n">iterations</span><span class="o">/</span><span class="n">elapsed</span>


<span class="c">#### TEST_PIPESPEED</span>

<span class="k">def</span> <span class="nf">pipe_func</span><span class="p">(</span><span class="n">c</span><span class="p">,</span> <span class="n">cond</span><span class="p">,</span> <span class="n">iterations</span><span class="p">):</span>
    <span class="n">a</span> <span class="o">=</span> <span class="s">'0'</span> <span class="o">*</span> <span class="mi">256</span>
    <span class="n">cond</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
    <span class="n">cond</span><span class="o">.</span><span class="n">notify</span><span class="p">()</span>
    <span class="n">cond</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">xrange</span><span class="p">(</span><span class="n">iterations</span><span class="p">):</span>
        <span class="n">c</span><span class="o">.</span><span class="n">send</span><span class="p">(</span><span class="n">a</span><span class="p">)</span>

    <span class="n">c</span><span class="o">.</span><span class="n">send</span><span class="p">(</span><span class="s">'STOP'</span><span class="p">)</span>

<span class="k">def</span> <span class="nf">test_pipespeed</span><span class="p">():</span>
    <span class="n">c</span><span class="p">,</span> <span class="n">d</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Pipe</span><span class="p">()</span>
    <span class="n">cond</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Condition</span><span class="p">()</span>
    <span class="n">elapsed</span> <span class="o">=</span> <span class="mi">0</span>
    <span class="n">iterations</span> <span class="o">=</span> <span class="mi">1</span>

    <span class="k">while</span> <span class="n">elapsed</span> <span class="o">&lt;</span> <span class="n">delta</span><span class="p">:</span>
        <span class="n">iterations</span> <span class="o">*=</span> <span class="mi">2</span>

        <span class="n">p</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">pipe_func</span><span class="p">,</span>
                                    <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">d</span><span class="p">,</span> <span class="n">cond</span><span class="p">,</span> <span class="n">iterations</span><span class="p">))</span>
        <span class="n">cond</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
        <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>
        <span class="n">cond</span><span class="o">.</span><span class="n">wait</span><span class="p">()</span>
        <span class="n">cond</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

        <span class="n">result</span> <span class="o">=</span> <span class="bp">None</span>
        <span class="n">t</span> <span class="o">=</span> <span class="n">_timer</span><span class="p">()</span>

        <span class="k">while</span> <span class="n">result</span> <span class="o">!=</span> <span class="s">'STOP'</span><span class="p">:</span>
            <span class="n">result</span> <span class="o">=</span> <span class="n">c</span><span class="o">.</span><span class="n">recv</span><span class="p">()</span>

        <span class="n">elapsed</span> <span class="o">=</span> <span class="n">_timer</span><span class="p">()</span> <span class="o">-</span> <span class="n">t</span>
        <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>

    <span class="k">print</span> <span class="n">iterations</span><span class="p">,</span> <span class="s">'objects passed through connection in'</span><span class="p">,</span><span class="n">elapsed</span><span class="p">,</span><span class="s">'seconds'</span>
    <span class="k">print</span> <span class="s">'average number/sec:'</span><span class="p">,</span> <span class="n">iterations</span><span class="o">/</span><span class="n">elapsed</span>


<span class="c">#### TEST_SEQSPEED</span>

<span class="k">def</span> <span class="nf">test_seqspeed</span><span class="p">(</span><span class="n">seq</span><span class="p">):</span>
    <span class="n">elapsed</span> <span class="o">=</span> <span class="mi">0</span>
    <span class="n">iterations</span> <span class="o">=</span> <span class="mi">1</span>

    <span class="k">while</span> <span class="n">elapsed</span> <span class="o">&lt;</span> <span class="n">delta</span><span class="p">:</span>
        <span class="n">iterations</span> <span class="o">*=</span> <span class="mi">2</span>

        <span class="n">t</span> <span class="o">=</span> <span class="n">_timer</span><span class="p">()</span>

        <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">xrange</span><span class="p">(</span><span class="n">iterations</span><span class="p">):</span>
            <span class="n">a</span> <span class="o">=</span> <span class="n">seq</span><span class="p">[</span><span class="mi">5</span><span class="p">]</span>

        <span class="n">elapsed</span> <span class="o">=</span> <span class="n">_timer</span><span class="p">()</span><span class="o">-</span><span class="n">t</span>

    <span class="k">print</span> <span class="n">iterations</span><span class="p">,</span> <span class="s">'iterations in'</span><span class="p">,</span> <span class="n">elapsed</span><span class="p">,</span> <span class="s">'seconds'</span>
    <span class="k">print</span> <span class="s">'average number/sec:'</span><span class="p">,</span> <span class="n">iterations</span><span class="o">/</span><span class="n">elapsed</span>


<span class="c">#### TEST_LOCK</span>

<span class="k">def</span> <span class="nf">test_lockspeed</span><span class="p">(</span><span class="n">l</span><span class="p">):</span>
    <span class="n">elapsed</span> <span class="o">=</span> <span class="mi">0</span>
    <span class="n">iterations</span> <span class="o">=</span> <span class="mi">1</span>

    <span class="k">while</span> <span class="n">elapsed</span> <span class="o">&lt;</span> <span class="n">delta</span><span class="p">:</span>
        <span class="n">iterations</span> <span class="o">*=</span> <span class="mi">2</span>

        <span class="n">t</span> <span class="o">=</span> <span class="n">_timer</span><span class="p">()</span>

        <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">xrange</span><span class="p">(</span><span class="n">iterations</span><span class="p">):</span>
            <span class="n">l</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
            <span class="n">l</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

        <span class="n">elapsed</span> <span class="o">=</span> <span class="n">_timer</span><span class="p">()</span><span class="o">-</span><span class="n">t</span>

    <span class="k">print</span> <span class="n">iterations</span><span class="p">,</span> <span class="s">'iterations in'</span><span class="p">,</span> <span class="n">elapsed</span><span class="p">,</span> <span class="s">'seconds'</span>
    <span class="k">print</span> <span class="s">'average number/sec:'</span><span class="p">,</span> <span class="n">iterations</span><span class="o">/</span><span class="n">elapsed</span>


<span class="c">#### TEST_CONDITION</span>

<span class="k">def</span> <span class="nf">conditionspeed_func</span><span class="p">(</span><span class="n">c</span><span class="p">,</span> <span class="n">N</span><span class="p">):</span>
    <span class="n">c</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
    <span class="n">c</span><span class="o">.</span><span class="n">notify</span><span class="p">()</span>

    <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">xrange</span><span class="p">(</span><span class="n">N</span><span class="p">):</span>
        <span class="n">c</span><span class="o">.</span><span class="n">wait</span><span class="p">()</span>
        <span class="n">c</span><span class="o">.</span><span class="n">notify</span><span class="p">()</span>

    <span class="n">c</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>

<span class="k">def</span> <span class="nf">test_conditionspeed</span><span class="p">(</span><span class="n">Process</span><span class="p">,</span> <span class="n">c</span><span class="p">):</span>
    <span class="n">elapsed</span> <span class="o">=</span> <span class="mi">0</span>
    <span class="n">iterations</span> <span class="o">=</span> <span class="mi">1</span>

    <span class="k">while</span> <span class="n">elapsed</span> <span class="o">&lt;</span> <span class="n">delta</span><span class="p">:</span>
        <span class="n">iterations</span> <span class="o">*=</span> <span class="mi">2</span>

        <span class="n">c</span><span class="o">.</span><span class="n">acquire</span><span class="p">()</span>
        <span class="n">p</span> <span class="o">=</span> <span class="n">Process</span><span class="p">(</span><span class="n">target</span><span class="o">=</span><span class="n">conditionspeed_func</span><span class="p">,</span> <span class="n">args</span><span class="o">=</span><span class="p">(</span><span class="n">c</span><span class="p">,</span> <span class="n">iterations</span><span class="p">))</span>
        <span class="n">p</span><span class="o">.</span><span class="n">start</span><span class="p">()</span>

        <span class="n">c</span><span class="o">.</span><span class="n">wait</span><span class="p">()</span>

        <span class="n">t</span> <span class="o">=</span> <span class="n">_timer</span><span class="p">()</span>

        <span class="k">for</span> <span class="n">i</span> <span class="ow">in</span> <span class="nb">xrange</span><span class="p">(</span><span class="n">iterations</span><span class="p">):</span>
            <span class="n">c</span><span class="o">.</span><span class="n">notify</span><span class="p">()</span>
            <span class="n">c</span><span class="o">.</span><span class="n">wait</span><span class="p">()</span>

        <span class="n">elapsed</span> <span class="o">=</span> <span class="n">_timer</span><span class="p">()</span><span class="o">-</span><span class="n">t</span>

        <span class="n">c</span><span class="o">.</span><span class="n">release</span><span class="p">()</span>
        <span class="n">p</span><span class="o">.</span><span class="n">join</span><span class="p">()</span>

    <span class="k">print</span> <span class="n">iterations</span> <span class="o">*</span> <span class="mi">2</span><span class="p">,</span> <span class="s">'waits in'</span><span class="p">,</span> <span class="n">elapsed</span><span class="p">,</span> <span class="s">'seconds'</span>
    <span class="k">print</span> <span class="s">'average number/sec:'</span><span class="p">,</span> <span class="n">iterations</span> <span class="o">*</span> <span class="mi">2</span> <span class="o">/</span> <span class="n">elapsed</span>

<span class="c">####</span>

<span class="k">def</span> <span class="nf">test</span><span class="p">():</span>
    <span class="n">manager</span> <span class="o">=</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Manager</span><span class="p">()</span>

    <span class="n">gc</span><span class="o">.</span><span class="n">disable</span><span class="p">()</span>

    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing Queue.Queue</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_queuespeed</span><span class="p">(</span><span class="n">threading</span><span class="o">.</span><span class="n">Thread</span><span class="p">,</span> <span class="n">Queue</span><span class="o">.</span><span class="n">Queue</span><span class="p">(),</span>
                    <span class="n">threading</span><span class="o">.</span><span class="n">Condition</span><span class="p">())</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing multiprocessing.Queue</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_queuespeed</span><span class="p">(</span><span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span><span class="p">,</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Queue</span><span class="p">(),</span>
                    <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Condition</span><span class="p">())</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing Queue managed by server process</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_queuespeed</span><span class="p">(</span><span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span><span class="p">,</span> <span class="n">manager</span><span class="o">.</span><span class="n">Queue</span><span class="p">(),</span>
                    <span class="n">manager</span><span class="o">.</span><span class="n">Condition</span><span class="p">())</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing multiprocessing.Pipe</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_pipespeed</span><span class="p">()</span>

    <span class="k">print</span>

    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing list</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_seqspeed</span><span class="p">(</span><span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">))</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing list managed by server process</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_seqspeed</span><span class="p">(</span><span class="n">manager</span><span class="o">.</span><span class="n">list</span><span class="p">(</span><span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">)))</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing Array("i", ..., lock=False)</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_seqspeed</span><span class="p">(</span><span class="n">multiprocessing</span><span class="o">.</span><span class="n">Array</span><span class="p">(</span><span class="s">'i'</span><span class="p">,</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">),</span> <span class="n">lock</span><span class="o">=</span><span class="bp">False</span><span class="p">))</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing Array("i", ..., lock=True)</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_seqspeed</span><span class="p">(</span><span class="n">multiprocessing</span><span class="o">.</span><span class="n">Array</span><span class="p">(</span><span class="s">'i'</span><span class="p">,</span> <span class="nb">range</span><span class="p">(</span><span class="mi">10</span><span class="p">),</span> <span class="n">lock</span><span class="o">=</span><span class="bp">True</span><span class="p">))</span>

    <span class="k">print</span>

    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing threading.Lock</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_lockspeed</span><span class="p">(</span><span class="n">threading</span><span class="o">.</span><span class="n">Lock</span><span class="p">())</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing threading.RLock</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_lockspeed</span><span class="p">(</span><span class="n">threading</span><span class="o">.</span><span class="n">RLock</span><span class="p">())</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing multiprocessing.Lock</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_lockspeed</span><span class="p">(</span><span class="n">multiprocessing</span><span class="o">.</span><span class="n">Lock</span><span class="p">())</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing multiprocessing.RLock</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_lockspeed</span><span class="p">(</span><span class="n">multiprocessing</span><span class="o">.</span><span class="n">RLock</span><span class="p">())</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing lock managed by server process</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_lockspeed</span><span class="p">(</span><span class="n">manager</span><span class="o">.</span><span class="n">Lock</span><span class="p">())</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing rlock managed by server process</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_lockspeed</span><span class="p">(</span><span class="n">manager</span><span class="o">.</span><span class="n">RLock</span><span class="p">())</span>

    <span class="k">print</span>

    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing threading.Condition</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_conditionspeed</span><span class="p">(</span><span class="n">threading</span><span class="o">.</span><span class="n">Thread</span><span class="p">,</span> <span class="n">threading</span><span class="o">.</span><span class="n">Condition</span><span class="p">())</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing multiprocessing.Condition</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_conditionspeed</span><span class="p">(</span><span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span><span class="p">,</span> <span class="n">multiprocessing</span><span class="o">.</span><span class="n">Condition</span><span class="p">())</span>
    <span class="k">print</span> <span class="s">'</span><span class="se">\n\t</span><span class="s">######## testing condition managed by a server process</span><span class="se">\n</span><span class="s">'</span>
    <span class="n">test_conditionspeed</span><span class="p">(</span><span class="n">multiprocessing</span><span class="o">.</span><span class="n">Process</span><span class="p">,</span> <span class="n">manager</span><span class="o">.</span><span class="n">Condition</span><span class="p">())</span>

    <span class="n">gc</span><span class="o">.</span><span class="n">enable</span><span class="p">()</span>

<span class="k">if</span> <span class="n">__name__</span> <span class="o">==</span> <span class="s">'__main__'</span><span class="p">:</span>
    <span class="n">multiprocessing</span><span class="o">.</span><span class="n">freeze_support</span><span class="p">()</span>
    <span class="n">test</span><span class="p">()</span>
</pre></div>
</div>
</div>
</div>


          </div>
        </div>
      </div>
      <div class="sphinxsidebar">
        <div class="sphinxsidebarwrapper" style="float: left; margin-right: 0px; width: 202px; top: 39px;">
  <h3><a href="http://docs.python.org/2/contents.html">Table Of Contents</a></h3>
  <ul>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#">16.6. <tt class="docutils literal"><span class="pre">multiprocessing</span></tt> — Process-based “threading” interface</a><ul>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#introduction">16.6.1. Introduction</a><ul>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#the-process-class">16.6.1.1. The <tt class="docutils literal"><span class="pre">Process</span></tt> class</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#exchanging-objects-between-processes">16.6.1.2. Exchanging objects between processes</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#synchronization-between-processes">16.6.1.3. Synchronization between processes</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#sharing-state-between-processes">16.6.1.4. Sharing state between processes</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#using-a-pool-of-workers">16.6.1.5. Using a pool of workers</a></li>
</ul>
</li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#reference">16.6.2. Reference</a><ul>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#process-and-exceptions">16.6.2.1. <tt class="docutils literal"><span class="pre">Process</span></tt> and exceptions</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#pipes-and-queues">16.6.2.2. Pipes and Queues</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#miscellaneous">16.6.2.3. Miscellaneous</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#connection-objects">16.6.2.4. Connection Objects</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#synchronization-primitives">16.6.2.5. Synchronization primitives</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#shared-ctypes-objects">16.6.2.6. Shared <tt class="docutils literal"><span class="pre">ctypes</span></tt> Objects</a><ul>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.sharedctypes">16.6.2.6.1. The <tt class="docutils literal"><span class="pre">multiprocessing.sharedctypes</span></tt> module</a></li>
</ul>
</li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#managers">16.6.2.7. Managers</a><ul>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#namespace-objects">16.6.2.7.1. Namespace objects</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#customized-managers">16.6.2.7.2. Customized managers</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#using-a-remote-manager">16.6.2.7.3. Using a remote manager</a></li>
</ul>
</li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#proxy-objects">16.6.2.8. Proxy Objects</a><ul>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#cleanup">16.6.2.8.1. Cleanup</a></li>
</ul>
</li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.pool">16.6.2.9. Process Pools</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.connection">16.6.2.10. Listeners and Clients</a><ul>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#address-formats">16.6.2.10.1. Address Formats</a></li>
</ul>
</li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#authentication-keys">16.6.2.11. Authentication keys</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#logging">16.6.2.12. Logging</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#module-multiprocessing.dummy">16.6.2.13. The <tt class="docutils literal"><span class="pre">multiprocessing.dummy</span></tt> module</a></li>
</ul>
</li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#programming-guidelines">16.6.3. Programming guidelines</a><ul>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#all-platforms">16.6.3.1. All platforms</a></li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#windows">16.6.3.2. Windows</a></li>
</ul>
</li>
<li><a class="reference internal" href="http://docs.python.org/2/library/multiprocessing.html#examples">16.6.4. Examples</a></li>
</ul>
</li>
</ul>

  <h4>Previous topic</h4>
  <p class="topless"><a href="http://docs.python.org/2/library/dummy_thread.html" title="previous chapter">16.5. <tt class="docutils literal docutils literal docutils literal"><span class="pre">dummy_thread</span></tt> — Drop-in replacement for the <tt class="docutils literal docutils literal docutils literal"><span class="pre">thread</span></tt> module</a></p>
  <h4>Next topic</h4>
  <p class="topless"><a href="http://docs.python.org/2/library/mmap.html" title="next chapter">16.7. <tt class="docutils literal docutils literal"><span class="pre">mmap</span></tt> — Memory-mapped file support</a></p>
<h3>This Page</h3>
<ul class="this-page-menu">
  <li><a href="http://docs.python.org/2/bugs.html">Report a Bug</a></li>
  <li><a href="http://docs.python.org/2/_sources/library/multiprocessing.txt" rel="nofollow">Show Source</a></li>
</ul>

<div id="searchbox" style="">
  <h3>Quick search</h3>
    <form class="search" action="http://docs.python.org/2/search.html" method="get">
      <input type="text" name="q" size="18">
      <input type="submit" value="Go">
      <input type="hidden" name="check_keywords" value="yes">
      <input type="hidden" name="area" value="default">
    </form>
    <p class="searchtip" style="font-size: 90%">
    Enter search terms or a module, class or function name.
    </p>
</div>
<script type="text/javascript">$('#searchbox').show(0);</script>
        </div>
      <div id="sidebarbutton" title="Collapse sidebar" style="color: rgb(255, 255, 255); border-left-width: 1px; border-left-style: solid; border-left-color: rgb(19, 63, 82); font-size: 1.2em; cursor: pointer; height: 49061px; padding-top: 1px; margin-left: 218px;"><span style="display: block; margin-top: 247px;">«</span></div></div>
      <div class="clearer"></div>
    </div>
    <div class="related">
      <h3>Navigation</h3>
      <ul>
        <li class="right" style="margin-right: 10px">
          <a href="http://docs.python.org/2/genindex.html" title="General Index">index</a></li>
        <li class="right">
          <a href="http://docs.python.org/2/py-modindex.html" title="Python Module Index">modules</a> |</li>
        <li class="right">
          <a href="http://docs.python.org/2/library/mmap.html" title="16.7. mmap — Memory-mapped file support">next</a> |</li>
        <li class="right">
          <a href="http://docs.python.org/2/library/dummy_thread.html" title="16.5. dummy_thread — Drop-in replacement for the thread module">previous</a> |</li>
        <li><img src="./16.6. multiprocessing — Process-based “threading” interface — Python v2.7.5 documentation_files/py.png" alt="" style="vertical-align: middle; margin-top: -1px"></li>
        <li><a href="http://www.python.org/">Python</a> »</li>
        <li>
          <span class="version_switcher_placeholder"><select><option value="3.4">dev (3.4)</option><option value="3.3">3.3</option><option value="3.2">3.2</option><option value="2.7" selected="selected">2.7.5</option><option value="2.6">2.6</option></select></span>
          <a href="http://docs.python.org/2/index.html">Documentation</a> »
        </li>

          <li><a href="http://docs.python.org/2/library/index.html">The Python Standard Library</a> »</li>
          <li><a href="http://docs.python.org/2/library/someos.html">16. Optional Operating System Services</a> »</li> 
      </ul>
    </div>
    <div class="footer">
    © <a href="http://docs.python.org/2/copyright.html">Copyright</a> 1990-2013, Python Software Foundation.
    <br>
    The Python Software Foundation is a non-profit corporation.
    <a href="http://www.python.org/psf/donations/">Please donate.</a>
    <br>
    Last updated on Oct 19, 2013.
    <a href="http://docs.python.org/2/bugs.html">Found a bug</a>?
    <br>
    Created using <a href="http://sphinx.pocoo.org/">Sphinx</a> 1.0.7.
    </div>

  
</body></html>