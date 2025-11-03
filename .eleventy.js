const data = require('./information.json');


function get_index(_title){
  const idx = data.titles.indexOf(_title);
  return idx;
}

function get_picture(img_index) {
  const image=data.images[img_index];
  const alt=data.alts[img_index];
  return `<img src="/images/${image}" alt="${alt}" class="picture">`
}

function index_text(title){
  const _index = get_index(title);
  const _text = data.texts[_index];
  return `<p>${_text}</p>`
}

function index_pic(title){
  const _index = get_index(title);
  return get_picture(_index);
}

function index_heading(title){
  const _index = get_index(title);
  const _heading = data.headings[_index];
  return `<h1>${_heading}</h1>`
}

function build_page(title){
  const _index = get_index(title);
  const _heading = index_heading(title);
  const _pic = get_picture(_index);
  const _text = index_text(title);
  return `
  ${_heading}
  <div class="contentpage">
    ${_pic}
    ${_text}
  </div>
  `;
}
// The export statement makes these settings available to other files in 11ty
module.exports = function(eleventyConfig) {
  eleventyConfig.addPassthroughCopy("images");
  eleventyConfig.addPassthroughCopy("styles");

  eleventyConfig.addShortcode("index_pic", function(title){
    const _index = get_index(title);
    return get_picture(_index)
  }
  )
  eleventyConfig.addShortcode("index_text", function(title){
    const _index = get_index(title);
    const _text = data.texts[_index];
    return `<p>${_text}</p>`
  }
  )

  eleventyConfig.addShortcode("index_page", function(title){

   return build_page(title)
  })
}