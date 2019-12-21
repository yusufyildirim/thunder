/**
 * Copyright (c) 2017-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

module.exports = {
  title: 'Thunder',
  tagline: 'Web framework, without hassle.',
  url: 'https://ttinythings.github.io/thunder/docs',
  baseUrl: '/',
  favicon: 'img/favicon.ico',
  organizationName: 'ttinythings', // Usually your GitHub org/user name.
  projectName: 'thunder', // Usually your repo name.
  themeConfig: {
    navbar: {
      title: 'Thunder',
      logo: {
        alt: 'Thunder',
        src: 'img/logo.svg',
      },
      links: [
        {to: 'docs/what-and-why', label: 'Docs', position: 'left'},
        {to: 'blog', label: 'Blog', position: 'left'},
        {
          href: 'https://github.com/facebook/docusaurus',
          label: 'GitHub',
          position: 'right',
        },
      ],
    },
    prism: {
      defaultLanguage: 'reason',
    },
    footer: {
      style: 'dark',
      copyright: `Copyright © ${new Date().getFullYear()} Tinythings OÜ.`,
    },
  },
  presets: [
    [
      '@docusaurus/preset-classic',
      {
        docs: {
          sidebarPath: require.resolve('./sidebars.js'),
        },
        theme: {
          customCss: require.resolve('./src/css/custom.css'),
        },
      },
    ],
  ],
};
